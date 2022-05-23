#include <SPI.h>


int triggerPin = 10;
int echoPin = 9;
int count=0;
int IRSensor = 2;
int capacity=40;
// the setup routine runs once when you press reset:
void setup() {
count=0;
capacity=40;
  Serial.begin(9600);
  pinMode(6, OUTPUT);
pinMode (IRSensor, INPUT);
SPI.begin(); 

}

// the loop routine runs over and over again forever:
void loop() {
//Serial.println(count);
if(count<40)
{
  

   long sensorReading = readUltrasonicDistance();
  long millimeters = sensorReading/2 * .343;
//  Serial.println(millimeters);
  if(millimeters <100){
    
//    if(count>=0 && count<40)
    {
      count++;
      Serial.print("total Cars inside :");
      Serial.println(count);

        Serial.print("Available spaces are :");
    Serial.println( capacity - count);Serial.println("");
    }
  }
}

if(count>0)
{
  int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 0){
    
//    if(count>=0 && count<40)
    {count--;
      Serial.print("total Cars inside :");
      Serial.println(count);

        Serial.print("Available spaces are :");
    Serial.println( capacity - count);Serial.println("");
    }
     
  }

}
  if(count==40)
  {
     Serial.println("Parking Lot is FULL!!!");
     
  }
  
delay(200);


}


long readUltrasonicDistance()
{
  // Clear the trigger
  pinMode(triggerPin, OUTPUT);
  
  //Send a 10 microsecond "HIGH" signal to prompt the sensor to start
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  
  // Read the echo pin, and return the sound wave travel time in microseconds
  pinMode(echoPin, INPUT);
  long pulseTime = pulseIn(echoPin, HIGH);
  return pulseTime;
}
