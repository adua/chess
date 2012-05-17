
 // pins2-9 = ground
 // pins10-13 thru analog = supply

int columns[8] = {10, 11, 12, 13, A0, A1, A2, A3};  //GND pins
int rows[8] = {2, 3, 4, 5, 6, 7, 8, 9};   //supply pins

void setup() 
{     
    
  for (int i = 2; i <= 10; i++)
  {
    pinMode(i, OUTPUT);  // set supply pins as output
  }
  
//  for (int i = 10; i <= 13; i++)
//  {
//    pinMode(i, INPUT);  // set ground pins as input
//  }
//
//  pinMode(A0, INPUT);
//  pinMode(A1, INPUT);
//  pinMode(A2, INPUT);
//  pinMode(A3, INPUT);
}

void lightLED(int r, int c)
  {
    digitalWrite(r, HIGH);
    pinMode(c, OUTPUT);
    delay(200);
    digitalWrite(r, LOW);
    pinMode(c, INPUT);
    delay(200);     
  }      

void loop() 
{

   digitalWrite(3, HIGH);
   digitalWrite(10, LOW);
   delay(200);
   digitalWrite(2, LOW);
   delay(200);
//   for (int r = 0; r <= 7 ; r++)
//  {
//    for (int c = 0; c <= 7; c++)
//    {
//      lightLED(rows[r], columns[c]);  
//    }
//  }   
//  
}




