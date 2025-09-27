const unsigned int TIMER_INT = 31;
const unsigned int WDT_INT = 30;
const unsigned int NOTE_INT = 29;

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
