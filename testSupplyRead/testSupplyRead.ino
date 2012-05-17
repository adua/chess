// set analog input pins
const int in_pin = A0;

// initialize values
int readValue = 0;

//define quiescient values
int qui[3] = {0,0,0};

int r0 = 0;
int r1= 0;
int r2 = 0;

int i = 0;

void setup() 
{
  Serial.begin(9600);
  
  pinMode(2, OUTPUT); //INH control
  
  pinMode(4, OUTPUT); //s0 supply
  pinMode(5, OUTPUT); //s1 supply
  pinMode(6, OUTPUT); //s2 supply
  
  pinMode(11, OUTPUT); //s0 read
  pinMode(12, OUTPUT); //s1 read
  pinMode(13, OUTPUT); //s2 read
  
  digitalWrite(2, HIGH); //INH ON
  
  delay(500);
  //Get the "default" values of the pins to compare with later
  for (i = 0; i <= 2; i++)
  {
  
  r0 = bitRead(i, 0);
  r1 = bitRead(i, 1);
  r2 = bitRead(i, 2); 
 
  digitalWrite(11, r0);
  digitalWrite(12, r1);
  digitalWrite(13, r2);
 
  delay(1000); 
  qui[i] = analogRead(in_pin); 
  delay(100);
  Serial.println(qui[i]);
  
  }
  
  digitalWrite(2, LOW); //INH OFF  

}
  

// multiplexer/demultiplexer function (y output, starting input pin)

   

void loop() {
  
  for (i = 0; i <= 2; i++)
  {
  
  r0 = bitRead(i, 0);
  r1 = bitRead(i, 1);
  r2 = bitRead(i, 2); 
 
  digitalWrite(4, r0);
  digitalWrite(5, r1);
  digitalWrite(6, r2); 
  
  delay(100);
  
  digitalWrite(11, r0);
  digitalWrite(12, r1);
  digitalWrite(13, r2);
   
   readValue = analogRead(in_pin);
  
   Serial.print("sensor" );
   Serial.print(i);
   Serial.print(" = ");   
   Serial.println(readValue - qui[i]);      
   delay(100);   
   
   Serial.println("--------------");
//    Serial.print("Switch: ");
//    Serial.print(r0);
//    Serial.print(r1);
//    Serial.print(r2);
//    Serial.print("\n");
    
    delay(500);
 

  }
  
}
