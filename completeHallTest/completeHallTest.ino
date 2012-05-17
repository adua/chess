// set analog input pins
const int in_pin = A0;

// initialize values
int readValue = 0;
int normVal = 0;

//define quiescient values
int qui[64];
int square1 = 0;
int square2 = 0;

int r0 = 0;   // top level bits
int r1= 0;
int r2 = 0;

int s0 = 0;  // bottom level bits
int s1 = 0;
int s2 = 0;



void setup() 
{
  Serial.begin(9600);
  
  for (int i = 2; i <= 13; i++)
  {
    pinMode(i, OUTPUT); //define output pins
  }
  
  delay(10);
  //Get the "default" values of the pins to compare with later
  for (int j = 0; j <= 7; j++) //columns
  {
    r0 = bitRead(j, 0);
    r1 = bitRead(j, 1);
    r2 = bitRead(j, 2);
    
    // provides init supply (Top of cascade)
    digitalWrite(2, r0);
    digitalWrite(3, r1);
    digitalWrite(4, r2);
            
    // provides init read (Top of cascade)
    digitalWrite(8, r0);
    digitalWrite(9, r1);
    digitalWrite(10, r2);
    
    delay(10);
   
    
    for (int i = 0; i <= 7; i++) //rows
    {
    
      s0 = bitRead(i, 0);
      s1 = bitRead(i, 1);
      s2 = bitRead(i, 2);
      
     // supply
      digitalWrite(5, s0);
      digitalWrite(6, s1);
      digitalWrite(7, s2); 
    
     
     //read
      digitalWrite(11, s0);
      digitalWrite(12, s1);
      digitalWrite(13, s2);
    
      delay(10);
     
      
     //stores values while ON, no magnets
      square1 = i*8;
      square1 = square1 +j;
      qui[square1] = analogRead(in_pin); 
      delay(10);
      Serial.print (square1);
      Serial.print (":  ");
      Serial.println(qui[square1]);
      
    
      
      
    
     }
  }
  
    Serial.println("Lez do this");

}
  

// multiplexer/demultiplexer function (y output, starting input pin)

   
void loop() 
{
  
  for (int j = 0; j <= 7; j++) //columns
  {
    r0 = bitRead(j, 0);
    r1 = bitRead(j, 1);
    r2 = bitRead(j, 2);
    
    // provides init supply (Top of cascade)
    digitalWrite(2, r0);
    digitalWrite(3, r1);
    digitalWrite(4, r2);
            
    // provides init read (Top of cascade)
    digitalWrite(8, r0);
    digitalWrite(9, r1);
    digitalWrite(10, r2);
    
    delay(10);
   
    
    for (int i = 0; i <= 7; i++) //rows
    {
    
      s0 = bitRead(i, 0);
      s1 = bitRead(i, 1);
      s2 = bitRead(i, 2);
      
     // supply
      digitalWrite(5, s0);
      digitalWrite(6, s1);
      digitalWrite(7, s2); 
     
     //read
      digitalWrite(11, s0);
      digitalWrite(12, s1);
      digitalWrite(13, s2);
    
      delay(10);
 
     square2 = i*8;
     square2 = square2 +j;
     readValue = analogRead(in_pin);
     normVal = readValue - qui[square2];
     if (normVal >= 30 || normVal <= -30)
     {
         Serial.println(square2);
     }


    }
  
  }
}
