// There are many lines of code dedicated to debugging the program with the arduino serial monitor.
// You will need to comment those lines out for the labVIEW interface program to work properly.
// needs this library because we are doing port manipulation to clean things up

#include <pins_arduino.h>
 
//Global variables for how many cycles have been currently run and how many cycles we want to run
long cycles = 1000;
long currentCycle = 0;
 
//global variables for pwm settings and a lastlowtime variable used with millis() function for
//compensating time outside of delay functions used to perform pwm
//all variables in milliseconds!!!

unsigned long highPeriod = 500000;
unsigned long lowPeriod = 500000;
unsigned long interval;
unsigned long lastLowTime;
unsigned long currentMicros;
unsigned long previousMicros;
 
//global variable for system status
String systemStatus = "idle";
boolean outputStatus;
 
void setup() {
 
  //Start serial for output with 115k baud rate.
  Serial.begin(115200);

  while (!Serial);      // Wait for serial port to connect. Needed for native USB or so they say :)
 
  //Send introduction

  //  Serial.println("==============================================================");
  //  Serial.println("filename: SolenoidValveDurabilityTester.ino");
  //  Serial.println("PWM Controller for durability tester");
  //  Serial.println("Description:");
  //  Serial.println("- Recieves instructions from host to control PWM and ");
  //  Serial.println("- monitor the number of cycles have been performed");
  //  Serial.println("Instructions:");
  //  Serial.println("H: Set high period (highPeriod)(mS).");
  //  Serial.println("L: Set low period. (lowPeriod)(mS)");
  //  Serial.println("B: Begin durability testing.");
  //  Serial.println("E: End durability testing.");
  //  Serial.println("C: Set cycle count (cycles).");
  //  Serial.println("R: Reset current cycle count (currentCycle = 0).");
  //  Serial.println("G: Get system status (systemStatus), current cycle count (currentCycle/cycles), high period (highPeriod)(mS),low period. (lowPeriod)(mS)"  .");
  //  Serial.println("version history:");
  //  Serial.println("2022/03/16 REL v0.1  ");
  //  Serial.println("==============================================================");
  //  Serial.print('\n');

  //Set up digital pins as output pins
  DDRD = DDRD | B11100000; // Sets D5,D6, and D7 as output. DRD port D controls pins 0-7
  DDRB = DDRB | B00011111; // Sets D8 to D12 as output DRD port B controls pins 8-15

}
 
 
void loop() {
  //run function that checks serial buffer for instructions
  checkForInstructions();
  //runs test if status is running LOL
  if (systemStatus == "Running") {
    //check for transitions :)
    checkForStateTransition();
    // check if we have reached target cycles and stops testing if we do
    if (currentCycle >= cycles) {
      systemStatus = "idle";
      //Force start low period because we do not want outputs to stay on if we turn it off
      PORTD &= B00011111; //Sets D5,D6, and D7 as High. Port D controls pins 0-7
      PORTB &= B11100000; // Sets D8 to D12 as High. Port B controls pins 8-15
    }
   }
}

 //Check serial buffer for instructions
void checkForInstructions() {
  //check serial buffer skip if empty
  if (Serial.available() > 0) {
    //read serial buffer for a byte of data and handle it
    byte incomingByte = Serial.read();
    switch (incomingByte)
    {
      case 'H':
        //        Serial.println("H: Set high period (highPeriod)(uS).");
        //        Serial.println("Please end number with /n or new line ");
        //        run function that waits for and reads new variable from serial port
        highPeriod = SetLongFromSerial();
        //        Serial.print("Received new high period as ");
        //        Serial.println(highPeriod);
        break;

      case 'L':
        //        Serial.println("L: Set low period. (lowPeriod)(uS)");
        //        Serial.println("Please end number with /n or new line ");
        //run function that waits for and reads new variable from serial port
        lowPeriod = SetLongFromSerial();
        //        Serial.print("Received new low period as ");
        //        Serial.println(lowPeriod);
        break;

      case 'B':
        //        Serial.println("Received B: Begin durability testing.");
        //resets variables in preparation of starting
        systemStatus = "Running";
        outputStatus = false;
        previousMicros = 0;
        break;

      case 'E':
        //        Serial.println("Received E: End durability testing.");
        systemStatus = "Idle";
        //Force start low period because we do not want outputs to stay on if we turn it off
        PORTD &= B00011111; //Sets D5,D6, and D7 as High. Port D controls pins 0-7
        PORTB &= B11100000; // Sets D8 to D12 as High. Port B controls pins 8-15
        break;

      case 'C':
        //        Serial.println("C: Set cycle count (cycles).");
        //        Serial.println("Please end number with /n new line ");
        //run function that waits for and reads new variable from serial port
        cycles = SetLongFromSerial();
        //        Serial.print("Received new cycle count as ");
        //        Serial.println(cycles);
        break;

      case 'R':
        //        Serial.println("R: Reset current cycle count (currentCycle = 0).");
        currentCycle = 0;
        break;

      case 'G':
        //        Serial.println("G: Get system status (systemStatus), current cycle count (currentCycle,cycles), high period (highPeriod)(mS),low period. (lowPeriod)(mS)");
        Serial.print(systemStatus);
        Serial.print(",");
        Serial.print(currentCycle);
        Serial.print(",");
        Serial.print(cycles);
        Serial.print(",");
        Serial.print(highPeriod);
        Serial.print(",");
        Serial.print(lowPeriod);
        Serial.println(",");
        break;
    }
  }
}
 
void checkForStateTransition() {
  // Checks current status and sets interval variable
  if (outputStatus == false) {
    interval = lowPeriod;
  }
  else {
    interval = highPeriod;
  }
 
  // actual checks for transition
  currentMicros = micros();
  if (currentMicros - previousMicros >= (interval)) {
    // save the last time you blinked the LEDs
    previousMicros = currentMicros;
     if (outputStatus == false) {
      //Increment cycle and check if its done when we go low to high
      currentCycle = currentCycle + 1;
      //start high period
      PORTD |= B11100000; //Sets D5,D6, and D7 as High. Port D controls pins 0-7
      PORTB |= B00011111; // Sets D8 to D12 as High. Port B controls pins 8-15
    }
    else {
      //Start low period
      PORTD &= B00011111; //Sets D5,D6, and D7 as High. Port D controls pins 0-7
      PORTB &= B11100000; // Sets D8 to D12 as High. Port B controls pins 8-15
    }
    outputStatus = !outputStatus;
  }
}
 
//Bullshit function to wait and read new long integer and returns it from function

//Apparently the ".toInt()" function works with long according to interwebs :)

long SetLongFromSerial() {
  long data;
  String incomingString;
  incomingString = Serial.readStringUntil('\n');
  while (Serial.available() == 0) {
  }
  incomingString = Serial.readStringUntil('\n');
  //  Serial.println(incomingString);
  data = incomingString.toInt();
  //  Serial.print("Received long ");
  //  Serial.println(data);
  return data;
}
