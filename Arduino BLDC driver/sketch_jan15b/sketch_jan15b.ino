
enum blinkStates {
  BLINK_DIS, // blink disable
  BLINK_EN, // blink enable
  LED_ON, // we want the led to be on for interval
  LED_OFF // we want the led to be off for interval
};

enum blinkStates ledState;
const int ledPin = 13;
long interval = 1000;
unsigned long previousMillis = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  // use ! and + characters to control the blinking.
  if (Serial.available() > 0) {
    char incomingByte = Serial.read();
    // turn off LED
    if (incomingByte == '!')
      ledState = BLINK_DIS;

    // turn on LED
    if (incomingByte == '+')
      ledState = BLINK_EN;
  }

  // enums are just integers, so let's see if
  // it has been enabled.
  if (ledState > BLINK_DIS) {
    if ((unsigned long)(currentMillis - previousMillis >= interval)) {
      // enough time has passed, let's change the state of the LED.
      if (ledState == LED_ON) {
        // time to turn off the LED
        ledState = LED_OFF;
        digitalWrite(ledPin, LOW);
      } else {
        // time to turn on the LED
        ledState = LED_ON;
        digitalWrite(ledPin, HIGH);
      }
      // reset our timer
      previousMillis = currentMillis;
    }
  } else if (ledState == BLINK_DIS) {
    // blinking is disabled, so turn off LED
    digitalWrite(ledPin, LOW);
  }
}
// Code by james@baldengineer.com
// More at: [permalink]
