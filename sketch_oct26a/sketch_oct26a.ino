int D0,D1,D2,D3;
void setup() 
{
 pinMode(19,INPUT); // setting 19,17,18,16 as input pins to take inputs from DTMF decoder circuit
 pinMode(18,INPUT);
 pinMode(17,INPUT);
 pinMode(16,INPUT);
 pinMode(7,OUTPUT);//setting 7,9,10 as output pins for functioning of LEDs
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 Serial.begin(9600);
}

void loop() 
{
  D0=digitalRead(19);// Read the input from the DTMF decoder circuit and store it in respective variables (D0,D1,D2,D3) 
  D1=digitalRead(18);
  D2=digitalRead(17);
  D3=digitalRead(16);
  if(D3==0 && D2==0 && D1==0 && D0==1) // check if the input is 1
  { 
    digitalWrite(7,HIGH);// glow only 1st led
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
  } 
   if(D3==0 && D2==0 && D1==1 && D0==0)// check if the input is 2
  { 
    digitalWrite(9,HIGH); // glow only 2nd led
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
  } 
   if(D3==0 && D2==0 && D1==1 && D0==1)// check if the input is 3
  { 
    digitalWrite(10,HIGH);// glow only 3rd led
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
  } 
   if(D3==0 && D2==1 && D1==0 && D0==0)// check if the input is 4
  { 
    digitalWrite(7,HIGH); // glow only 1st and 2nd led
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  } 
   if(D3==0 && D2==1 && D1==0 && D0==1)// check if the input is 5
  { 
    digitalWrite(7,HIGH); // glow only 1st and 3rd led
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
  } 
   if(D3==0 && D2==1 && D1==1 && D0==0)// check if the input is 6
  { 
    digitalWrite(9,HIGH); // glow only 2nd and 3rd led
    digitalWrite(10,HIGH);
    digitalWrite(7,LOW);
  } 
    if(D3==1 && D2==0 && D1==0 && D0==0)// check if the input is 8
  { 
    digitalWrite(7,HIGH);
    digitalWrite(9,HIGH); // glow all LEDs
    digitalWrite(10,HIGH);
  } 
   if(D3==1 && D2==0 && D1==1 && D0==0)// check if the input is 0
  { 
    digitalWrite(7,LOW);
    digitalWrite(9,LOW); //switch off all LEDs
    digitalWrite(10,LOW);
  } 
}
