/* Initialize the WDT peripheral */
void initWDT() {
  // TODO step 3: configure WDTCR (foundation Q6.1-6.2)
  // NOTE: write all four bitfields at once using bitshifts, ors, and the _Pos macros!


  // Enable WDT when debugger is connected
  R_DEBUG->DBGSTOPCR_b.DBGSTOP_WDT = 0;
  R_WDT->WDTSR = 0; // clear watchdog status;

  // TODO step 3: Make the watchdog trigger an interrupt and use the ICU to connect it to the CPU
  // Configure WDT to trigger interrupt (foundation Q6.4):
  
  // attach the interrupt to CPU (foundation Q6.5):
  //configureMCUInterrupt(WDT_INT, ___, &wdtISR);
}

/* pet the watchdog */
void petWDT() {
  // TODO step 3: fill this in (foundation Q6.3)

}

/* ISR when WDT triggers */
void wdtISR() {
  Serial.println("WOOF!!!");
  while(true);
}
