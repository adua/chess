
int readLED = 0;
String LED = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() 
{
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  LED.reserve(200);
  
  for (int i = 2; i <= 10; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete)
  {
    int readLED = LED[0] - '0';
    Serial.println(readLED);
    digitalWrite(readLED+2, HIGH);
    delay(50);
    digitalWrite(readLED+2, LOW);
    // clear the string:
    delay(5);
    LED = "";
    stringComplete = false;
  }
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    LED += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}


