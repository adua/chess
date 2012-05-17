// set analog input pins
const int in_pin = A0;

// initialize values
int readValue = 0;
int normVal = 0;

//define quiescient values
int qui[8] = {0,0,0,0,0,0,0,0};

int r0 = 0;
int r1= 0;
int r2 = 0;

int i = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(4, OUTPUT); //s0 supply
  pinMode(5, OUTPUT); //s1 supply
  pinMode(6, OUTPUT); //s2 supply
  
  pinMode(7, OUTPUT); //s0 supply init
  pinMode(8, OUTPUT); //s1 supply init
  pinMode(9, OUTPUT); //s2 supply init
  
  pinMode(11, OUTPUT); //s0 read
  pinMode(12, OUTPUT); //s1 read
  pinMode(13, OUTPUT); //s2 read

  
  delay(10);
  //Get the "default" values of the pins to compare with later
  for (i = 0; i <= 7; i++)
  {
    
  // provides init supply (Top of cascade)
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW); 
    
  r0 = bitRead(i, 0);
  r1 = bitRead(i, 1);
  r2 = bitRead(i, 2); 
  
 // supply
  digitalWrite(4, r0);
  digitalWrite(5, r1);
  digitalWrite(6, r2); 
 
  delay(10);
 
 //read
  digitalWrite(11, r0);
  digitalWrite(12, r1);
  digitalWrite(13, r2);

  delay(10);
 
 //stores values while ON, no magnets
  qui[i] = analogRead(in_pin); 
  delay(10);
  //Serial.println(qui[i]);
  
  }
  
  //delay(2000);
  //Serial.println("Setup finished");
  

}
  

// multiplexer/demultiplexer function (y output, starting input pin)

   

void loop() {
  
  for (i = 0; i <= 7; i++)
  {
  
  r0 = bitRead(i, 0);
  r1 = bitRead(i, 1);
  r2 = bitRead(i, 2); 
 
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW); 
  
  delay(5);
  
  digitalWrite(4, r0);
  digitalWrite(5, r1);
  digitalWrite(6, r2); 
  
  delay(5);
  
  digitalWrite(11, r0);
  digitalWrite(12, r1);
  digitalWrite(13, r2);
   
   readValue = analogRead(in_pin);
   normVal = readValue - qui[i];
   if (normVal >= 50 || normVal <= -50)
   {
     Serial.print(i);
   }
   
//     Serial.print("sensor ");
//     Serial.println(": POS Gauss");
//   }
//   else if (normVal <= -50)
//   {
//     Serial.print("sensor ");
//     Serial.print(i);
//     Serial.println(": NEG Gauss");
//   }
//   else
//   {
//   }
//   
  
//   Serial.print("sensor" );
//   Serial.print(i);
//   Serial.print(" = ");   
//   Serial.println(readValue - qui[i]);      
//   delay(10);   
   
//   Serial.println("--------------");
//    Serial.print("Switch: ");
//    Serial.print(r0);
//    Serial.print(r1);
//    Serial.print(r2);
//    Serial.print("\n");
    


  }
  
}
