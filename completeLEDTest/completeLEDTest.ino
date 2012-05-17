#include <math.h>


int ledArray[5] = {0, 2, 4, 6, 8};

int rows[8] = {10, 11, 12, 13, A0, A1, A2, A3};
int columns[8] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup()
{
  Serial.begin(9600);
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
}


void loop()
{
  
  int length = 0;
  length = sizeof(ledArray)/sizeof(int);
  
  lightLEDArray(ledArray, length);
//  for (int r = 0; r <= 7; r++)
//  {    
//    for (int c = 0; c <= 7; c++)
//    {
//      
//      lightLED(rows[r], columns[c]);
//     
//    }
//    
//  }
 
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
  
  for (int i=0;i<length;i++){
   row = getCoordRow(leds[i]);
   col = getCoordCol(leds[i]);
   
   lightLED(rows[row], columns[col]); 
  }
  
  
}
