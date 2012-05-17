
#include <string.h>

int ledArray[64];
String ledSquares = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


int rows[8] = {10, 11, 12, 13, A0, A1, A2, A3};
int columns[8] = {2, 3, 4, 5, 6, 7, 8, 9};


void setup() 
{
  // initialize serial:
  Serial.begin(9600);
  
  // reserve 400 bytes for the inputString:
  ledSquares.reserve(400);
  
  for (int i = 2; i <= 13; i++)
 { 
  pinMode(i, INPUT);
  digitalWrite(i, LOW);
  delay(10);
 }
  

  pinMode(A0, INPUT);
  digitalWrite(A0, LOW);
  pinMode(A1, INPUT);
  digitalWrite(A1, LOW);
  pinMode(A2, INPUT);
  digitalWrite(A2, LOW);
  pinMode(A3, INPUT);
  digitalWrite(A3, LOW);
  delay(10);
  
  Serial.println("Setup complete");
  
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete)
  {
    
    int lengthArray = ledSquares.length()+1;
    char tempChar[lengthArray];
    ledSquares.toCharArray(tempChar, lengthArray); 
    
    char  * pch;
    pch = strtok(tempChar,",");
    int i = 0;
    while (pch != NULL)
    {
      
       ledArray[i] = atoi(pch);
       pch = strtok(NULL, ",");
       i++;
      
    }
     
     
 
    // clear the string:
    delay(5);

    //ledSquares = "";
    stringComplete = false;
    
    
  }
     int length = 0;
     length = sizeof(ledArray)/sizeof(int);
     lightLEDArray(ledArray, length);
     
    Serial.print("ledArray = ");
    for (int i = 0; i<length; i++)
    {
      Serial.print(ledArray[i]);
      Serial.print(", ");
    }
     
     Serial.println();

   
}


void serialEvent() 
{
 ledSquares = ""; 
 for (int i = 0; i< 64; i++)
{
   ledArray[i] = 0;
} 
  while (Serial.available()) 
  {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    ledSquares += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    Serial.print("String: ");
    Serial.println(ledSquares);
    } 
  }
}

//Light a single LED
//@col = column, @row = row 

void lightLED(int row, int col) {
    
     pinMode(row, OUTPUT);
     digitalWrite(row, HIGH);
     pinMode(col, OUTPUT);
     digitalWrite(col, LOW);
     delay(50);
     pinMode(row, INPUT);
     digitalWrite(row, LOW); 
     pinMode(col, INPUT);
     digitalWrite(col, LOW);
     delay(50);
  
}


//Given row, col we get the square #
int getSquare(int row, int col) {
  int square = 0;
  square = row * 8 + col;  
  return square;
  
}


//Given square, get row
int getCoordRow(int square){
  int row = 0;
  row = (square/8);
  return row;
  
}

//Given square, get col
int getCoordCol(int square){
  int col = 0;
  col = square % 8;
  return col;
  
}


//Light all given LEDs
//@leds = array of LEDs to light with square numbers
void lightLEDArray(int leds[], int length) {
  
  int row = 0;
  int col = 0;
  
  for (int i=0;i<length;i++)
  {
    if (leds[i] != 0)
    {
       int val = 0;
       val = leds[i] - 1;
       row = getCoordRow(val);
       col = getCoordCol(val);
       lightLED(rows[row], columns[col]); 
     }
  }
    
}



