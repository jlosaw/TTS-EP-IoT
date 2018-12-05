//Arithmetic Operators

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


//Incrementors

void setup() {
  Serial.begin(9600);       // use the serial port for printing the number
}

int count = 0;              // the number to print

void loop() {
  Serial.println(count++);  // print and increment the number
  delay(1000);              // 1 second delay between printing
}

//For Loops

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    Serial.print("i = ");
    Serial.println(i);
  }
  delay(1000);
}

//While Loops

void setup() {
  int sum = 0;
  
  Serial.begin(9600);
  
  // count up to 25 in 5s
  while (sum < 25) {
    sum = sum + 5;
    Serial.print("sum = ");
    Serial.println(sum);
    delay(500);                // 500ms delay
  }
}

void loop() {
}


//Do While Loops

void setup() {
  int sum = 0;
  
  Serial.begin(9600);
  
  // count up to 25 in 5s
  do {
    sum = sum + 5;
    Serial.print("sum = ");
    Serial.println(sum);
    delay(500);                // 500ms delay
  } while (sum < 25);
}

void loop() {
}

//If Statements

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);  // LED on pin 13 of UNO
}

void loop() {
  char rx_byte;

  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();
    if (rx_byte == 'a') {
      digitalWrite(7, HIGH);
    }
  }
}


//If-Else Statements

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);  // LED on pin 13 of UNO
}

void loop() {
  char rx_byte;

  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();
    if (rx_byte == 'a') {
      digitalWrite(7, HIGH);
    }
   else {
      // switch the LED off if any character except 'a' is received
      digitalWrite(7, LOW);
    }
  }
}


//If-Else If Statements

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);  // LED on pin 7 of UNO
}

char rx_byte = 0;

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();
  }
  if (rx_byte == 'a') {
    digitalWrite(7, HIGH);
    delay(1000);
    digitalWrite(7, LOW);
    delay(1000);
  }
  else if (rx_byte == 'b') {
    digitalWrite(7, HIGH);
    delay(200);
    digitalWrite(7, LOW);
    delay(200);
  }
}


//Other Logic

 Or (||)
  if (rx_byte == 'a' || rx_byte == 'A') {
      digitalWrite(7, HIGH);
    }

AND (&&)
  if ((first_char == 'c') && (rx_byte == 'd')) {
      digitalWrite(7, HIGH);
    }

NOT (!)
if (!(rx_byte == 'a')) {
      digitalWrite(7, HIGH);
    }


//Conditional Expression


int val1, val2, result;

void setup() {
  Serial.begin(9600);

  // change the values of val1 and val2 to see what the
  // conditional expression does
  val1 = 2;
  val2 = 5;
  // if val1 is bigger than val2, return val1
  // else if val1 is less than val2, return val2
  result = (val1 > val2) ? val1 : val2;

  // show result in serial monitor window
  Serial.print("The bigger number is: ");
  Serial.println(result);
}

void loop() {
}


//Functions

void setup() {
  Serial.begin(9600);
  
  DashedLine();
  Serial.println("| Program Menu |");
  DashedLine();
}

void loop() {
}

void DashedLine()
{
  Serial.println("----------------");
}

//Send Value to a Function


void setup() {
  Serial.begin(9600);

  // draw the menu box
  DashedLine(24);
  Serial.println("| Program Options Menu |");
  DashedLine(24);
}

void loop() {
}

void DashedLine(int len)
{
  int i;

  // draw the line
  for (i = 0; i < len; i++) {
    Serial.print("-");
  }
  // move the cursor to the next line
  Serial.println("");
}

//Get Data From Function

void setup() {
    Serial.begin(9600);
    Serial.print("Area of circle is: ");
    // print area to 4 decimal places
    Serial.println(CircleArea(9.2), 4);
}

void loop() {
}

// calculate the area of a circle
float CircleArea(float radius)
{
    return (3.141592654 * radius * radius);
}


//Arrays

  void setup() {
  int my_array[5];     // an array with 5 integer elements
  int i;               // used as an index into the array
  
  Serial.begin(9600);
  
  my_array[0] = 23;    // assign a value of 23 to the 1st element
  my_array[1] = 1001;  // assign a value of 1001 to the 2nd element, etc.
  my_array[2] = 9;
  my_array[3] = 1234;
  my_array[4] = 987;
  
  // display each number from the array in the serial monitor window
  for (i = 0; i < 5; i++) {
    Serial.println(my_array[i]);
  }
}

void loop() {
}

//Strings

void setup() {
  String my_str = "This is my string.";

  Serial.begin(9600);

  // (1) print the string
  Serial.println(my_str);

  // (2) change the string to upper-case
  my_str.toUpperCase();
  Serial.println(my_str);

  // (3) overwrite the string
  my_str = "My new string.";
  Serial.println(my_str);

  // (4) replace a word in the string
  my_str.replace("string", "Arduino sketch");
  Serial.println(my_str);

  // (5) get the length of the string
  Serial.print("String length is: ");
  Serial.println(my_str.length());
}

void loop() {
}




