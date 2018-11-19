//This sketch runs a few standard arithmatic operators to show how they are evaluated

void setup() {
  int a = 2;
  int b = 7;
  int result;
  float result_fl;

  Serial.begin(9600);

  Serial.print("Addition (a + b): ");
  result = a + b;
  Serial.println(result);

  Serial.print("Subtraction (10 - 2): ");
  result = 10 - 2;
  Serial.println(result);

  Serial.print("Multiplication (4 * 3): ");
  result = 4 * 3;
  Serial.println(result);

  Serial.print("Int Division (5 / 4): ");
  result = 5 / 4;
  Serial.println(result);

  Serial.print("Float Division (5.0 / 4.0): ");
  result_fl = 5.0 / 4.0;
  Serial.println(result_fl);

  Serial.print("Remainder (11 % 4): ");
  result = 11 % 4;
  Serial.println(result);
}

void loop() {
}
