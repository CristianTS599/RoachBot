// Cristian Torres, Yanni Buzey, Week 8 Robot Project
// Assigning pins from Arduino to Motor Board

//Servo Stuff
const int trigPin = A5;       
const int echoPin = A4;  
const int LookLeft = 160;  
const int LookRight = 20;
const int Straightahead = 90;
int Delaytime = 2000;  

long duration;
int distance;

#include <Servo.h>
Servo myservo;

//Motor Stuff
int ENB = 5;
int IN4 = 6;
int IN3 = 7;
int IN2 = 8;
int IN1 = 9;
int ENA = 11;

int drtn = 2000;
int SPD = 255;
int duration2 = 5000;
int SPD2 = 0;

//Setting these pins as outputs to go into the motorboard
void setup() {
pinMode (ENB, OUTPUT); 
pinMode (IN4, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN2, OUTPUT);
pinMode (IN1, OUTPUT);
pinMode (ENA, OUTPUT);

                           
   pinMode(trigPin, OUTPUT);   
   pinMode(echoPin, INPUT);    
   Serial.begin(9600); 
   myservo.attach(3);

}

//This is the list of instructions for what the robot does
void loop() {

if (distance > 24) FWD(1000, 150);

if (distance < 12) BRAKE(1000);

myservo.write(Straightahead);
  delay(Delaytime);
    digitalWrite(trigPin, LOW);          
  delayMicroseconds(2);//(Microseconds)
  digitalWrite(trigPin, HIGH);        //sends the 20us wave
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH);  // echoPin is measuring distance of pulse
  distance = duration*0.034/2/2.54;
  Serial.print("Center: ");
  Serial.print(distance);
  Serial.println("in");                        

}

void FWD(int duration, int SPD)
{
  // -- MOTOR B
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  // -- MOTOR A
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  analogWrite(ENA, SPD);
  analogWrite(ENB, SPD);
  delay (1000);

}

void BRAKE (int duration) // robot will brake quickly
{
digitalWrite(IN1, LOW);  // all motors off
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
delay (1000);
}

void REV(int duration, int SPD)// robot will reverse for 1 second at 200
{
  // -- MOTOR B
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  // -- MOTOR A
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  analogWrite(ENA,SPD);
  analogWrite(ENB, SPD);
  delay (1000);
}



