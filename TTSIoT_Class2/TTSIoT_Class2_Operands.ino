//This sketch shows the execution of differentn operands

void setup() {
  int a = 2;
  int b = 3;

  Serial.begin(9600);

  Serial.print("Is a greater than b? ");
  Serial.println(a > b);

  Serial.print("Is a less than 25? ");
  Serial.println(a < 25);

  Serial.print("Is a greater than or equal to b? ");
  Serial.println(a >= b);

  a = 3;
  Serial.print("Is a greater than or equal to b? ");
  Serial.println(a >= b);

  a = 4;
  Serial.print("Is a greater than or equal to b? ");
  Serial.println(a >= b);

  Serial.print("Is a equal to b? ");
  Serial.println(a == b);

  b = 4;
  Serial.print("Is a equal to b? ");
  Serial.println(a == b);

}

void loop() {
}
