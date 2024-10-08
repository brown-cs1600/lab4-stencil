/* Initialize GPT peripheral for playing notes */
void initGPT() {
  R_MSTP->MSTPCRD_b.MSTPD6 = 0; // Enable GPT peripheral
  // Make sure the count isn't started
  R_GPT2->GTCR_b.CST = 0;
  // Make sure nobody else can start the count (see 22.2.5 and 22.2.6)
  R_GPT2->GTSSR = (1 << R_GPT0_GTSSR_CSTRT_Pos); // only started w/ software
  R_GPT2->GTPSR = (1 << R_GPT0_GTPSR_CSTOP_Pos); // only stopped w/ software

  // TODO step 1 (Prelab Q5.1): Divide the GPT2 clock
  // IMPORTANT: because of a versioning issue between Arduino and Renesas, use the actual bit position *number* from the datasheet
  // instead of the field name macro defined in the header file
  // See https://github.com/arduino/ArduinoCore-renesas/issues/354 for more info
  R_GPT2->GTCR = ;

  // Disable GPT interrupt on ICU for now
  R_ICU->IELSR[TIMER_INT] = 0;
  // Use the Arm CMSIS API to enable CPU interrupts
  // (overall GPT interrupt is enabled only when notes play; see playNote)
  NVIC_SetVector((IRQn_Type) TIMER_INT, (uint32_t) &gptISR); // set vector entry to our handler
  NVIC_SetPriority((IRQn_Type) TIMER_INT, 14); // Priority lower than Serial (12)
  NVIC_EnableIRQ((IRQn_Type) TIMER_INT);

  // TODO step 4:
  //initNoteGPT();
}

/*
 * Sets configures GPT2 interrupt to play note at desired frequency
 * Non-blocking: note can play while program executes
 */
void playNote(int freq) {
  // Turn off counting while configuring
  R_GPT2->GTCR_b.CST = 0;

  // TODO step 1: Configure GPT2 to count to correct n
  // Reference prelab Q3.1 for calculation of n
  // Reference prelab Q5.2 for the GPT2 register
  // Remember that the clock frequency is stored in the constant CLOCKFREQ
  R_GPT2->___ = ;

  // TODO step 1 (Prelab Q5.4):
  // Configure the ICU to connect the GPT interrupt to the CPU interrupt to enable interrupt
  R_ICU->IELSR[TIMER_INT] = (___ << R_ICU_IELSR_IELS_Pos);

  // TODO step 1: re-enable the GPT count

}

/* Stop playing a note */
void stopPlay() {
  // TODO step 1: Turn off GPT counter and disable CPU interrupt via ICU
  R_GPT2->___ = ;
  R_ICU->___ = ;
  
  // TODO step 2: Turn off pin
  R_PFS->PORT[OUT_PORT].PIN[OUT_PIN].___ = ;
}

/*
 * Play a given note for a given duration (a frequency of 0 is a rest, i.e. no sound should play for the duration)
 * Blocking: everything except interrupts will have to wait for this function
 */
void playNoteDuration(int freq, int durMillis) {
  // TODO step 1: use playNote and stopPlay to write this function

}

/* ISR that toggles a GPIO pin low/high at a configuered frequency */
void gptISR() {
  intcount++; // USED FOR TESTING: DO NOT REMOVE

  // TODO step 2: Toggle output pin (use lab3 as reference if needed)
  R_PFS->PORT[OUT_PORT].PIN[OUT_PIN].___ = ;

  // TODO step 1: restart count

  // TODO step 1: clear interrupt on MCU and CPU side (just like in Lab 3)

}

/* TODO step 4: Enable interrupt to control which notes are played when */
void initNoteGPT() {
  // Setp up GPT3 (similarly to what initGPT did for GPT2)

  // kick off first noteISR by setting a counter value and turning on the counter
}

/* TODO step 4: make an ISR control the song, instead of loop() */
void noteISR() {
  // stop the GPT3 counter
  
  // Stop current note and play the next note (just like loop/playNoteDuration did)

  // Set up the next noteISR by setting a counter value and turning on GPT3 counter
  
  // Remember to clear any pending flags!

}
