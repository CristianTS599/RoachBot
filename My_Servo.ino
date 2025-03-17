



const int trigPin = A5;
const int echoPin = A4;
long duration;
int distance;
#include <Servo.h>
Servo myservo; 

int pos = 20<=160;
 

void setup() {
  //Engages pins
     myservo.attach(3); 
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
     Serial.begin(9600); 
     
  // turns ultrasonic sensor on
    digitalWrite(trigPin, LOW);          
    delayMicroseconds(2);//(Microseconds)
    digitalWrite(trigPin, HIGH);        //sends the 20us wave
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); 
    duration = pulseIn(echoPin, HIGH);  // echoPin is measuring distance of pulse
    distance = duration*0.034/2/2.54;   // Speed of sound conversion
    
    // Tells Bot to print Right,Straight and Left for 20,90,160, Degrees
    
}

void loop() {
  Serial.print("right:); Serial.println(distance); if (pos = 20)
  // for loop, makes servo look from right(20deg),center(90),LEFT(160);
  for (pos = 20; pos <= 160; pos += 70) {     
    // in steps of 70 degree
     myservo.write(pos);              
     delay(2000);  
  }
    
  // for loop, makes servo look from left(160),center(90),right(20);
  /*for (pos = 160; pos >= 20; pos -= 70) { 
    myservo.write(pos);              
    delay(2000);   
    
    digitalWrite(trigPin, LOW);          
    delayMicroseconds(2);//(Microseconds)
  
    digitalWrite(trigPin, HIGH);        //sends the 20us wave
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    duration = pulseIn(echoPin, HIGH);  // echoPin is measuring distance of pulse
    distance = duration*0.034/2/2.54;

    Serial.print("distance: ");
    Serial.println(distance);
    delay(2000);  */                   
  }











