/**
 * Filename: BlinkLEDReport.ino
 * 
 * Purpose: Makes the LED blinking continuously and at the same time
 *          reporting to the output serial that the LED is blinking
 *          through Serial API.
 * 
 * Date: 04-10-2020
 * 
 */

/* GLOBALS */
int DigitalPin = 2;
int BaudRate = 9600; 

void setup() {
  /**
   * Initialise the serial port communication and output
   * instruction data to the second pin.
   */
  Serial.begin(BaudRate);
  pinMode(DigitalPin, OUTPUT);
  Serial.println("Initialising...");
}

void BlinkLed(void) {
  /* Just make the LED blink and delay for a second */
  delay(1000);
  digitalWrite(DigitalPin, LOW);
  delay(1000);
  digitalWrite(DigitalPin, HIGH);
}

void loop() {
  /**
   * Report through the COM3 serial port that the LED
   * is blinking.
   */
  Serial.println("The LED is blinking!");

  /* Make our LED blink */ 
  BlinkLed();
}
