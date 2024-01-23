#include <Arduino.h>
#include <TaskScheduler.h>

enum serial_commands {
  QUERY,                          //handles status query sends status like enable,current pos (if known),speed,direction,run vs stop vs stop $ hold
  ENABLE_DRIVE,                   //turns on power transistor to step 1 config. reminder create a map of 120deg patterns for cw and ccw
  SET_SPEED,                      //steps per second i think. placeholder
  SET_DIRECTION,                  //cw or ccw
  RUN,                            //keeps running at set speed and direction
  STOP,                           //stops run and turns off all six power transistors
  STOP_AND_HOLD_POSITION,         //stops run but keeps power transistor configuration on indefinitely
  CW_SINGLE_STEP,                 //moves one step cw then proceeds to stop and hold pos, need to keep track of current pos
  CCW_SINGLE_STEP,                //moves one step ccw then proceeds to stop and hold pos, need to keep track of current pos
};

enum DriveOutputState {
  IDLING,
  ENABLING_DRIVE,
  RUNNING
};

struct systemStatus {
  enum
  int enableStatus{0}; //0 is disabled and 1 is powered up or enabled
  int speed{0};//steps per sec bebe
  int direction{0}; // 0 is used as invalid, 1 is cw, and 2 is ccw
  bool moving{false}; //are we moving? if not moving and enabled we can assume holding
};

const int phase1_supply_pin {2};
const int phase1_common_pin {3};
const int phase2_supply_pin {4};
const int phase2_common_pin {5};
const int phase3_supply_pin {6};
const int phase3_common_pin {7};

int speed {1000};

int commutationSequence[6][6] = {
  {HIGH, LOW, LOW, HIGH, LOW, LOW},   // Phase 1 to supply
  {LOW, HIGH, LOW, HIGH, LOW, LOW},   // Phase 1 to common
  {LOW, LOW, HIGH, LOW, LOW, HIGH},   // Phase 2 to supply
  {LOW, LOW, LOW, HIGH, LOW, HIGH},   // Phase 2 to common
  {LOW, LOW, LOW, LOW, HIGH, HIGH},   // Phase 3 to supply
  {HIGH, LOW, LOW, LOW, HIGH, HIGH}   // Phase 3 to common
};


// Function prototypes
void handleCommand(serial_commands command, int data);

void setup() {
  //self explanatory just declaring modes for pins and setting them all to off before setting pins as outputs. don't want to risk them being default high for some reason
  digitalWrite(phase1_supply_pin, LOW);
  digitalWrite(phase1_common_pin, LOW);
  digitalWrite(phase2_supply_pin, LOW);
  digitalWrite(phase2_common_pin, LOW);
  digitalWrite(phase3_supply_pin, LOW);
  digitalWrite(phase3_common_pin, LOW);
  pinMode(phase1_supply_pin, OUTPUT);
  pinMode(phase1_common_pin, OUTPUT);
  pinMode(phase2_supply_pin, OUTPUT);
  pinMode(phase2_common_pin, OUTPUT);
  pinMode(phase3_supply_pin, OUTPUT);
  pinMode(phase3_common_pin, OUTPUT);


  //bullshit handshaking
  Serial.begin(9600); // Set the baud rate to match your serial monitor
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  establishContact();
}

void loop() {
  processSerialInput();
}

void processSerialInput(){
  if (Serial.available() > 0) {
    String commandString = Serial.readStringUntil('\n'); // Read the serial input until a newline character is received
    serial_commands command = static_cast<serial_commands>(commandString.toInt()); // Convert string to enum
    int data = checkCommandForData(commandString);
    // Handle the received command
    handleCommand(command, data);
  }
}

int checkCommandForData(String commandString) {
  if (commandString.indexOf(' ') == -1) {
    return -1; // no data coz there isnt a space
  }
  // Find the index of the space character
  int spaceIndex = commandString.indexOf(' ');
  String stringData = commandString.substring(spaceIndex + 1);
  if (stringData.length()==0) {
    return -2; // no data coz it was just a space
  }
  return stringData.toInt();
}

// Function to handle different commands
void handleCommand(serial_commands command, int data) {
  switch (command) {
    case QUERY:
      // Handle QUERY command
      Serial.println("Handling QUERY command");
      Serial.println(speed);
      break;
    case ENABLE_DRIVE:
      // Handle ENABLE_DRIVE command
      Serial.println("Handling ENABLE_DRIVE command");
      break;
    case SET_SPEED:
      {
        // Handle SET_SPEED command
        Serial.println("Handling SET_SPEED command");
        //Serial.println(commandString);
        if (data > 0) {
          speed = data;
          Serial.print("Speed is ");
          Serial.print(speed);
          Serial.println(" steps per seconds.");
        }
        else{
          Serial.println("speed entered is either invalid or zero. Set_speed command rejected");
        }
        break;
      }
    case SET_DIRECTION:
      // Handle SET_DIRECTION command
      Serial.println("Handling SET_DIRECTION command");
      break;
    case RUN:
      // Handle RUN command
      Serial.println("Handling RUN command");
      break;
    case STOP:
      // Handle STOP command
      Serial.println("Handling STOP command");
      break;
    case STOP_AND_HOLD_POSITION:
      // Handle STOP_AND_HOLD_POSITION command
      Serial.println("Handling STOP_AND_HOLD_POSITION command");
      break;
    case CW_SINGLE_STEP:
      // Handle CW_SINGLE_STEP command
      Serial.println("Handling CW_SINGLE_STEP command");
      break;
    case CCW_SINGLE_STEP:
      // Handle CCW_SINGLE_STEP command
      Serial.println("Handling CCW_SINGLE_STEP command");
      break;
    default:
      Serial.println("Invalid command");
      break;
  }

}


void establishContact() {
  while (Serial.available() <= 0) {
    delay(300);
  }
  Serial.println("3PH BLDC Driver Ready");   // send an initial string
}
