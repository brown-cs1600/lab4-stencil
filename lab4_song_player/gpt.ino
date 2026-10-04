// TODO step 1: clear/set appropriate bit in GPT register
// (see foundation Q5 overview)
#define GPT_OFF(r_gpt) ((r_gpt)->GTCR_b.___ = 0)
#define GPT_START(r_gpt) ((r_gpt)->GTCR_b.___ = 1)

/*
 * Tells ICU to connect given MCU event (determined by IELS bits) to given CPU interrupt channel
 * and provided ISR (this is the same code that you used in lab 3)
 */
//                         value 0-31               3-bit value             ISR function
void configureMCUInterrupt(unsigned int cpu_int_id, unsigned int IELS_bits, void(* isr)()) {
  R_ICU->IELSR[cpu_int_id] = IELS_bits << R_ICU_IELSR_IELS_Pos;
  NVIC_SetVector((IRQn_Type) cpu_int_id, (uint32_t) isr); // set vector entry to our handler
  NVIC_SetPriority((IRQn_Type) cpu_int_id, 14); // Priority lower than Serial (12)
  NVIC_EnableIRQ((IRQn_Type) cpu_int_id);
}

/*
 * Configures given GPT peripheral with given divisor (determined by TPCS bits)
 * Does NOT start the GPT count yet
 */
//                R_GPT2 or R_GPT3    3-bit value
void configureGPT(R_GPT0_Type* r_gpt, unsigned int TPCS_bits) {
  GPT_OFF(r_gpt);
  // Make sure nobody else can start the count (see 22.2.5 and 22.2.6)
  r_gpt->GTSSR = (1 << R_GPT0_GTSSR_CSTRT_Pos); // only started w/ software
  r_gpt->GTPSR = (1 << R_GPT0_GTPSR_CSTOP_Pos); // only stopped w/ software

  // TODO step 1: Divide the GPT clock
  // IMPORTANT: because of a versioning issue between Arduino and Renesas, use the actual bit position *number* from the datasheet
  // instead of the field name macro defined in the header file (you read about this bitfield in foundation Q5.1)
  // See https://github.com/arduino/ArduinoCore-renesas/issues/354 for more info
  r_gpt->GTCR = TPCS_bits << ___;
}

/*
 * Kicks off given GPT peripheral to count up to given number of ticks
 */
//                 R_GPT2 or R_GPT3
void startGPTcount(R_GPT0_Type* r_gpt, unsigned int ticks) {
  GPT_OFF(r_gpt);
  // TODO step 1: configure count (foundation Q5.3)
  r_gpt->___ = ticks;
  GPT_START(r_gpt);
}

/*
 * Configures GPT2 to interrupt at appropriate interval in order to play note of the given frequency
 * Non-blocking: note can play while program executes
 */
void playNote(int freq) {
  // TODO step 1: call with the correct number of ticks (foundation Q3.1)
  // refer to CLOCKFREQ (defined in lab4_song_player.ino) for pre-scaled frequency
  startGPTcount(R_GPT2, ___);
}

/* Stop playing a note */
void stopPlay() {
  GPT_OFF(R_GPT2);
  
  // TODO step 2: turn pin off
  //R_PFS->PORT[OUT_PORT].PIN[OUT_PIN].PmnPFS...
}

/*
 * Play a given note for a given duration (a frequency of 0 is a rest, i.e. no sound should play for the duration)
 * Blocking: everything except interrupts will have to wait for this function
 */
void playNoteDuration(int freq, int durMillis) {
  // TODO step 1: use playNote, stopPlay, and delay to implement this function

}

/*
 * ISR for GPT2 (fires at frequency determined by GPT2)
 * toggles a GPIO pin low/high
 */
void pinISR() {
  intcount++; // USED FOR TESTING: DO NOT REMOVE

  // TODO step 2: toggle pin
  //R_PFS->PORT[OUT_PORT].PIN[OUT_PIN].PmnPFS...

  GPT_START(R_GPT2); // restart GPT2 count immediately
  
  clearIRQ(PIN_INT);
}

/*
 * ISR for GPT3 (fires at period determined by GPT3)
 * interrupts after every note for non-blocking song playing
 * SELF-RESTARTING (re-configures GPT3 to count to next interval)
 */
void noteISR() {
  // TODO step 4: fill in, following the tips in the lab handout
  //const int GPT3_Hz = ___;
  static int songPos = 0;

  
  clearIRQ(NOTE_INT);
}
