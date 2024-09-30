/*
 * Plays note at the desired frequency
 * Computes the frequency at which the output pin is being toggled and compares it to the desired frequency
 * Margin of allowed error: maximum of (2% or 1ms)
 * Assumes GPT interrupts are disabled
 */
bool testNote(int testFreq, int durationMillis, bool verbose = false) {
  intcount = 0;
  unsigned long startTime = micros();
  playNoteDuration(testFreq, durationMillis);
  unsigned long endTime = micros();
  int elapsedTimeMillis = (int) (endTime - startTime) / 1000;
  if (verbose) {
    Serial.print("Expected duration: ");
    Serial.println(durationMillis);
    Serial.print("Measured duration: ");
    Serial.println(elapsedTimeMillis);
  }
  if (abs(elapsedTimeMillis - durationMillis) > durationMillis / 50) {
    return false;
  }
  if (verbose) {
    Serial.print("Expected frequency: ");
    Serial.println(testFreq);
    Serial.print("Measured frequency: ");
    Serial.println(1000 * intcount / (2 * durationMillis));
  }
  return abs((1000 * intcount / (2 * durationMillis)) - testFreq) <= max(1, testFreq/50);
}

/*
 * Cycles through all the pitches defined in pitches.h
 */
bool testAllNotes() {
  Serial.println("Testing all notes");
  for (int i = 0; i < 89; i++) {
    Serial.print("Testing frequency ");
    Serial.println(allNotes[i]);
    if (!testNote(allNotes[i], 500)) {
      // Test failed, rerun with verbose
      Serial.println("TEST FAILED");
      testNote(allNotes[i], 500, true);
      return false;
    }
  }
  Serial.println("All tests passed!");
  return true;
}
