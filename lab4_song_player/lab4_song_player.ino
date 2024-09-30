#include "rtttl_parser.h"
#include "lab4.h"

// TODO step 5
//#define SINUSOID

// TODO step 1 (Prelab Q4.3)
// Make sure this is in Hz! (i.e. since prelab was in MHz, multiply by the correct magnitude)
const int CLOCKFREQ = ;

// TODO step 2: configure port and pin for Arduino D4
const int OUT_PORT = ;
const int OUT_PIN = ;

const String song = "spooky:d=4,o=6,b=127:8c,f,8a,f,8c,b5,2g,8f,e,8g,e,8e5,a5,2f,8c,f,8a,f,8c,b5,2g,8f,e,8c,d,8e,1f,8c,8d,8e,8f,1p,8d,8e,8f_"
//const String song = "Short:d=16,o=5,b=140:b,8p,b,b,2b";
// TODO step 4
//const String song = "Pinkpanth:d=4,o=6,b=160:8d_5,8e5,2p,8f_5,8g5,2p,8d_5,8e5,16p,8f_5,8g5,16p,8c,8b5,16p,8d_5,8e5,16p,8b5,2a_5,2p,16a5,16g5,16e5,16d5,2e5";
int noteFrequencies[100];
int noteDurations[100];
int songLen;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Grab some *unused* CPU interrupts
  TIMER_INT = getNextCPUINT(1);
  WDT_INT = getNextCPUINT(TIMER_INT);
  NOTE_INT = getNextCPUINT(WDT_INT);

  analogWriteResolution(10);

  // TODO step 2: Set piezo speaker as output (refer to lab 3 as needed)
  R_PFS->PORT[OUT_PORT].PIN[OUT_PIN].___ = ;

  // TODO step 2: uncomment to parse song
  /*
  songLen = rtttlToBuffers(song, noteFrequencies, noteDurations);
  if (songLen == -1) {
    Serial.println("ERROR PARSING SONG!");
    while(true);
  }*/

  initGPT();
  Serial.println("GPT initialized!");

  intcount = 0; // for testing notes
  // TODO step 2: comment out once done testing
  testAllNotes();

  // TODO step 3: uncomment for WDT
  //initWDT();
  // pet WDT once to start the peripheral
  //petWDT();
}


void loop() {
  // TODO step 2: play a song
  // one call of loop() = one note of song played
  // player should pause for 2 seconds before resuming song

  // TODO step 3: pet the watchdog
  // petWDT();

  // TODO step 4: comment out the body of this function (or just put a return at the beginning)
}
