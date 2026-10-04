const unsigned int PIN_INT = 31;
const unsigned int WDT_INT = 30;
const unsigned int NOTE_INT = 29;

// Used to test interrupt: counts how many times the timer interrupt occurs
volatile int intcount;

/* Utils for testing notes */
bool testAllNotes();
bool testNote(int testFreq, int durationMillis, bool verbose);

/* Interrupt functionality */
void configureMCUInterrupt(unsigned int cpu_int_id, unsigned int IELS_bits, void(* isr)());
inline void clearIRQ(unsigned int cpu_int_id) {
    R_ICU->IELSR_b[cpu_int_id].IR = 0;
    NVIC_ClearPendingIRQ((IRQn_Type) cpu_int_id);
}
/* GPT functionality
   gpt.ino also defines these macros:
   GPT_OFF(r_gpt) (to stop count for given timer peripheral)
   GPT_START(r_gpt) (to start count for given timer peripheral)
 */
void configureGPT(R_GPT0_Type* r_gpt, unsigned int TPCS_bits);
void startGPTcount(R_GPT0_Type* r_gpt, unsigned int ticks);
void playNote(int freq);
void stopPlay();
void playNoteDuration(int freq, int durMillis);
void pinISR();
void noteISR();

/* WDT functionality */
void initWDT();
void petWDT();
void wdtISR();
