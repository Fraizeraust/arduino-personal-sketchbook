/**
 * Filename: TemperatureSensor.ino
 * 
 * Purpose: The red and blue LEDs turn ON accordingly based on the temperature value retrieved through
 *          the analog pin with the TMP sensor. A temperature range threshold determines which LED
 *          must shall turn ON.
 * 
 * Date: 18-10-2020
 * 
 */

/* GLOBALS */
int BaudRate = 9600;
int LedPins[2] = {2, 3};
const int TempPin = A1;
const float TempRange = 20.0; // 20.0 == 20° C, change it at your choice
float VoltageVal;
float TempVal;
int AdcVal;

/* OTHER STUFF */
typedef enum _TEMP_STATE  {
  HOT = 1,
  COLD
} TEMP_STATE;

#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof(x[0]))
void SetTempStateLED(TEMP_STATE State);

void setup() {
  unsigned int i;
  
  /* Initialise the serial port communication */
  Serial.begin(BaudRate);
  Serial.println("Initialise...");

  /** 
   *  Iterate over the digital pins in the array so we can
   *  outright turn OFF the LEDs prior to the initialisation
   *  process.
   */
   for (i = 0; i < SIZE_OF_ARRAY(LedPins); i++) {
    pinMode(LedPins[i], OUTPUT);
    digitalWrite(LedPins[i], LOW);
   }
}

/**
 * SetTempStateLED() is a small helper function to set the LED
 * light state condition based on the current temperature we get.
 * An invalid argument to the function call's parameter will lead
 * to an unexpected failure.
 */
void SetTempStateLED(TEMP_STATE State) {
  switch (State) {
    case HOT:
    {
      digitalWrite(LedPins[0], HIGH);
      digitalWrite(LedPins[1], LOW);
      break;
    }

    case COLD:
    {
      digitalWrite(LedPins[0], LOW);
      digitalWrite(LedPins[1], HIGH);
      break;
    }

    default:
      Serial.println("Invalid argument found, bail out!");
      break;
  }
}

void loop() {
  /* Read the ADC value from the sensor */
  AdcVal = analogRead(TempPin);

  /* Convert the ADC to voltage and then to Celsius */
  VoltageVal = (AdcVal / 1024.0) * 5.0;
  TempVal = (VoltageVal - .5) * 100;

  /* Print to the serial terminal the current temperature */
  Serial.println("The temperature right now is -> " + String(TempVal) + " °C");

  /* And also turn ON the specific LED based on the temperature */
  if (TempVal > TempRange)
    SetTempStateLED(HOT);
  else
    SetTempStateLED(COLD);

  /**
   * Delay for 10 seconds as we do not want
   * to gather the temperature that quickly. Otherwise
   * we'd end up with erroneous or not so consistent
   * values.
   */
   delay(10000);
}
