#include <Arduino.h>

//just function prototypes to make it cleaner
//ugly function that checks serial port for two numbers and puts them into predeclared variables 
int getTwoNumbers(int &num1, int &num2);
//ugly function that takes two numbers and sends them to serial port plus a cheeky message
void calculateAndSendSum(int num1, int num2);

//setup function
void setup() {
  Serial.begin(9600);
}

//main loop
void loop() {
  int num1, num2;
  
  if (getTwoNumbers(num1, num2)) {
    calculateAndSendSum(num1, num2);
  }
}

// start of functions

int getTwoNumbers(int &num1, int &num2) {
  int result{0};
  if (Serial.available() >= 2) {
    num1 = Serial.parseInt();
    num2 = Serial.parseInt();
    
    if (Serial.read() == '\n') {
      result = 1; // Return 1 to indicate successful parsing
    }
  }
  return result; // Return 0 if there are not enough bytes or the input is not complete
}

void calculateAndSendSum(int num1, int num2) {
  int sum = num1 + num2;
  Serial.println("Sum: " + String(sum));
  Serial.println("built and uploaded with platformIO 2");
}

