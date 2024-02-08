int getTwoNumbers(int &num1, int &num2) {
  if (Serial.available() >= 2) {
    num1 = Serial.parseInt();
    num2 = Serial.parseInt();
    
    if (Serial.read() == '\n') {
      return 1; // Return 1 to indicate successful parsing
    }
  }
  return 0; // Return 0 if there are not enough bytes or the input is not complete
}

void calculateAndSendSum(int num1, int num2) {
  int sum = num1 + num2;
  Serial.println("Sum: " + String(sum));
  Serial.println("Hallo");
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int num1, num2;
  
  if (getTwoNumbers(num1, num2)) {
    calculateAndSendSum(num1, num2);
  }
}
