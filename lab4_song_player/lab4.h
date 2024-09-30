/* Get next unused CPU interrupt > start */
unsigned int getNextCPUINT(unsigned int start) {
   unsigned int tryInt = start + 1;
      while (tryInt < 32) {
         if (NVIC_GetEnableIRQ((IRQn_Type) tryInt) == 0) {
            return tryInt;
         }
      tryInt++;
   }
}
unsigned int TIMER_INT;
unsigned int WDT_INT;
unsigned int NOTE_INT;

// Used to test interrupt: counts how many times the timer interrupt occurs
volatile int intcount;

/* Utils for testing notes */
bool testAllNotes();
bool testNote(int testFreq, int durationMillis, bool verbose);

/* GPT functionality */
void initGPT();
void playNote(int freq);
void playNoteDuration(int freq, int durMillis);
void stopPlay();
void gptISR();
void noteISR();

/* WDT functionality */
void initWDT();
void petWDT();
void wdtISR();