// Christian Torres, Yanni Buzey, Week 7 Robot Project

// Assigning pins from Arduino to Motor Board
int ENB = 5;
int IN4 = 6;
int IN3 = 7;
int IN2 = 8;
int IN1 = 9;
int ENA = 11;

int duration = 1000;
int SPD = 255;
int duration2 = 5000;
int SPD2 = 0;
/*
 * in1 and in2 and enable control motor a,
 * in 1high in2 low, = reverse, vice versa
 * enable is speed (o to 255)
 * 
 */

//Setting these pins as outputs to go into the motorboard
void setup() {
pinMode (ENB, OUTPUT); 
pinMode (IN4, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN2, OUTPUT);
pinMode (IN1, OUTPUT);
pinMode (ENA, OUTPUT);

}

//This is the list of instructions for what the robot does
void loop() {
FWD(1000, 255);
COAST(1000);
REV(1000, 255);
BRAKE(1000);
RIGHT(1000, 255);
LEFT(1000, 255);
STOP(7000, 0);
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

void COAST(int duration)// will coast to stop
{
analogWrite(ENA, 0);
analogWrite(ENB, 0);
delay (duration);
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

void BRAKE (int duration) // robot will brake quickly
{
digitalWrite(IN1, LOW);  // all motors off
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
delay (1000);
}

void LEFT(int duration,int SPD) // Robot starts spinning left
  {
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  delay(1000); // Delay to 2 seconds
 
  digitalWrite(IN1, LOW); // Turn the motor off
  digitalWrite(IN2, LOW);   
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW); 
}

void RIGHT(int duration, int SPD) // robot spins right
{
  digitalWrite(IN1, HIGH); // Turn HIGH motor A
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200);   // turning speed is 200
 
  digitalWrite(IN3, HIGH); // turn HIGH motor B
  digitalWrite(IN4, LOW);   
  analogWrite(ENB, 200);
  delay(1000);             // Delay to 1 seconds
  
}

void STOP(int duration2, int SPD2)// Robot stops after full cycle and waits 10 seconds to restart
{
  digitalWrite(IN1, LOW); // Turn the motor off
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW); 
  delay(10000);
}



