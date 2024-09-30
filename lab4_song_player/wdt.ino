/* Initialize the WDT peripheral */
void initWDT() {
  // TODO step 3 (prelab Qs6.1-6.2)
  // Remember to use a 100% refresh window, unlike the prelab!
  R_WDT->WDTCR = ;

  // Enable WDT when debugger is connected
  R_DEBUG->DBGSTOPCR_b.DBGSTOP_WDT = 0;
  R_WDT->WDTSR = 0; // clear watchdog status;

  // TODO step 3 (prelab Qs6.4-6.5): Make the watchdog trigger an interrupt
  // and use the ICU to connect it to the CPU
  // Make sure to call the correct CMSIS functions as well!
  R_WDT->___= ;
  R_ICU->IELSR[WDT_INT] = ;
  // CMSIS
}

/* pet the watchdog */
void petWDT() {
  // TODO step 3 (prelab Q6.3)
}

/* ISR when WDT triggers */
void wdtISR() {
  Serial.println("WOOF!!!");
  while(true);
}