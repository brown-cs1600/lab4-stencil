#include "rtttl_parser.h"
#include "lab4.h"

// TODO step 1: GPT2 clock frequency after pre-scaling (foundation Q4.3)
// Make sure this is in Hz! (i.e. since foundation was in MHz, multiply by the correct magnitude)
const int CLOCKFREQ = ;

// TODO step 2: set constants to correspond to pin D4
//const int OUT_PORT = ;
//const int OUT_PIN = ;

const String song = "spooky:d=4,o=6,b=127:8c,f,8a,f,8c,b5,2g,8f,e,8g,e,8e5,a5,2f,8c,f,8a,f,8c,b5,2g,8f,e,8c,d,8e,1f,8c,8d,8e,8f,1p,8d,8e,8f_";
//const String song = "Short:d=16,o=5,b=140:b,8p,b,b,2b";
// TODO step 4
//const String song = "Pinkpanth:d=4,o=6,b=160:8d_5,8e5,2p,8f_5,8g5,2p,8d_5,8e5,16p,8f_5,8g5,16p,8c,8b5,16p,8d_5,8e5,16p,8b5,2a_5,2p,16a5,16g5,16e5,16d5,2e5";
int noteFrequencies[100];
int noteDurations[100];
int songLen;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // TODO step 2: configure pin D4 as GPIO output
  //R_PFS->PORT[OUT_PORT].PIN[OUT_PIN].PmnPFS...

  // TODO step 2: uncomment (once done testing)
  /*
  songLen = rtttlToBuffers(song, noteFrequencies, noteDurations);
  if (songLen == -1) {
    Serial.println("ERROR PARSING SONG!");
    while(true);
  }
  */
  
  // TODO step 1: pass correct TPCS bits to prescale GPT2 (foundation Q5.1)
  configureGPT(R_GPT2, ___);
  // TODO step 1: pass correct IELS bits to configure GPT2 ISR (foundation Q5.4)
  configureMCUInterrupt(PIN_INT, ___, &pinISR);

  // TODO step 4: setup GPT3 (use the datasheet to look up the appropriate bit values!)
  // These will both be DIFFERENT values from the GPT2 values above
  //configureGPT(R_GPT3, ___);
  //configureMCUInterrupt(NOTE_INT, ___, &noteISR);
  
  // TODO step 4: kick off first GPT3 interrupt
  //startGPTcount(R_GPT3, ___);

  intcount = 0; // for testing notes
  // TODO step 2: remove once done testing
  testAllNotes();

  // TODO step 3: uncomment for WDT
  //initWDT();
  // TODO step 3: pet WDT once to start the peripheral
  //petWDT();
}

void loop() {
  // TODO step 2: play song stored in noteFrequencies/noteDurations
  // one call of loop() = one note of song played
  // player should pause for 2 seconds before resuming song

  static int songPos = 0;

  // TODO step 3: pet the watchdog
  //petWDT();

  // TODO step 4: comment out the body of this function (or just put a return at the beginning)
}
