// Dec 2022
// Arduino sketch
// Turn on/off a led connected to an Arduino Uno pin 13

#define LED 13
#define BAUDE_RATE 9600
#define DELAY 1000

#define LedOn   digitalWrite(LED,HIGH);
#define LedOff  digitalWrite(LED,LOW); 

String command = "off";

void setup() {
  Serial.begin(BAUDE_RATE);
  pinMode(LED, OUTPUT);
}

void loop() {
  
  while(Serial.available() == 0){ }
  
  command = Serial.readString();
  
  if (command == "off"){
     LedOff;
  } 
  
  if (command == "on"){
     LedOn;
  }
  delay(DELAY);        
}

