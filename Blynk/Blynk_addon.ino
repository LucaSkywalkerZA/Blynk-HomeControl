#include <SoftwareSerial.h>
String inc;
int count = 0;
int DataPin = 2;
int ClockPin = 3;
int LatchPin = 4; 
bool br, bb, bg, br1, bb1, bg1;
byte Data = 0;
void setup() {
  Serial.begin(9600);
  Serial.flush();
  pinMode(DataPin, OUTPUT); 
  pinMode(ClockPin, OUTPUT);  
  pinMode(LatchPin, OUTPUT);
}
void loop() {
  if (Serial.available() > 0) {
    inc = Serial.readString();
  }
 String redded = Serial.readString();
 int bol1 = rand()%100;
 int bol2 = rand()%100;
 int bol3 = rand()%100;
 int bol4 = rand()%100;
 int bol5 = rand()%100;
 int bol6 = rand()%100;
   if(bol1 > 49)
  {
    br = 0;
  }
  else{
    br = 1;
  }
   if(bol2 > 49)
   {
    bg = 0;
  }
  else{
    bg = 1;
  }
   if(bol3 > 49)
   {
    bb = 0;
  }
  else
  {
    bb = 1;
  }
     if(bol4 > 49)
  {
    br1 = 0;
  }
  else{
    br1 = 1;
  }
   if(bol5 > 49)
   {
    bg1 = 0;
  }
  else{
    bg1 = 1;
  }
   if(bol6 > 49)
   {
    bb1 = 0;
  }
  else
  {
    bb1 = 1;
  }
// if(redded.length()==3)
// {
//  char r = redded.charAt(0);
//  char g = redded.charAt(1);
//  char b = redded.charAt(2);
//  char r = bol1;
//  char g = bol2;
//  char b = bol3;
//  if(r == '0')
//  {
//    br = 0;
//  }
//  else{
//    br = 1;
//  }
//   if(g == '0')
//   {
//    bg = 0;
//  }
//  else{
//    bg = 1;
//  }
//   if(b == '0')
//   {
//    bb = 0;
//  }
//  else
//  {
//    bb = 1;
//  }
  shiftWrite(1, br);
  shiftWrite(2, bg);
  shiftWrite(3, bb);
  shiftWrite(4, br1);
  shiftWrite(5, bg1);
  shiftWrite(6, bb1);
  delay(100);
 }
//}
void shiftWrite(int Pin, boolean State)
{                                       
  bitWrite(Data,Pin,State);             
  shiftOut(DataPin, ClockPin, MSBFIRST, Data);
  digitalWrite(LatchPin, HIGH);
  digitalWrite(LatchPin, LOW);
}
void increment() 
{
  int PinNo = 0;
  int Delay = 100; 
  
  for(PinNo = 0; PinNo < 8; PinNo++)
  {
    shiftWrite(PinNo, HIGH);
    delay(Delay);                
  }
  for(PinNo = 7; PinNo >= 0; PinNo--)
  {
    shiftWrite(PinNo, LOW);
    delay(Delay);                
  }
}
void OneByOne()
{
  int PinNo = 0;
  int Delay = 50; 
  
  for(PinNo = 0; PinNo < 8; PinNo++)
  {
    shiftWrite(PinNo, HIGH);
    delay(Delay); 
    shiftWrite(PinNo, LOW);    
  }
  for(PinNo = 7; PinNo >=0 ; PinNo--)
  {
    shiftWrite(PinNo, HIGH);
    delay(Delay); 
    shiftWrite(PinNo, LOW);    
  }
}
void AllHigh()
{
  int PinNo = 0;
  for(PinNo = 0; PinNo < 8; PinNo++)
  {
   shiftWrite(PinNo, HIGH);  
  }
}
void AllLow()
{
  int PinNo = 0;
  for(PinNo = 0; PinNo < 8; PinNo++)
  {
   shiftWrite(PinNo, LOW);  
  }
}
