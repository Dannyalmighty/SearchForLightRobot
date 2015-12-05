
#include <Servo.h>

Servo servoRight; 
Servo servoLeft;

unsigned long echo = 0;
int ultraSoundSignal = 30; // Ultrasound signal pin
unsigned long ultrasoundValue = 0;


void setup() 
{
  servoRight.attach(3);  // attaches the servo on pin 3 to the servo object
  servoLeft.attach(4);  // attaches the servo on pin 4 to the servo object

  Serial.begin(9600);
  pinMode(ultraSoundSignal,OUTPUT);
}

unsigned long ping()
{ 
  pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignal, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignal, LOW); // Holdoff
  pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignal, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
  echo = pulseIn(ultraSoundSignal, HIGH); //Listen for echo
  ultrasoundValue = (echo / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValue;
}

void forward() 
{
  servoLeft.write(180);
  servoRight.write(0);
}

void reverse() 
{
  servoLeft.write(0);
  servoRight.write(180);
}

void turnLeft() 
{
  servoLeft.write(0);
  servoRight.write(0);
}
void turnRight() 
{
  servoLeft.write(180);
  servoRight.write(180);
}

void halt() 
{
  servoLeft.write(90);
  servoRight.write(90);
}

void stopRobotCompletely() 
{
  exit(0);
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void loop()
{
  forward();
  delay(100);
  
  int x = 0;
  x = ping();
  Serial.println(x);
  delay(100);
  if( x < 12 )
  {
    turnLeft();
    delay(240);
  }

}
