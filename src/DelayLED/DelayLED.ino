/**
 * Filename: DelayLED.ino
 * 
 * Purpose: Enable and disables each connected LED through the specific pins
 *          in a delayed fashion. 
 * 
 * Date: 23-04-2020
 * 
 */

void setup() {
  /* Set all the used pins as OUTPUT mode as we want to alter their behaviour */
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  /* Set their corresponding pins to ground state before playing with the LEDs */ 
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  /* Delay each LED voltage state for 1 second in order */
  digitalWrite(4, LOW);
  digitalWrite(2, HIGH);

  /* Delay and go for the next LED */
  delay(1000);

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

  delay(1000);

  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);

  /* Delay again for another 1 second and repeat the cycle */
  delay(1000);
}
