#include <Servo.h>
#define photoD 2
#define photoL 3       // x is pin connected to on board
#define photoR 4       // x is pin connected to on board


Servo servoRight; 
Servo servoLeft;
Servo linearArm;

unsigned long echoF = 0;
int ultraSoundSignalF = 30; // Ultrasound signal pin
unsigned long ultrasoundValueF = 0;

unsigned long echoL = 0;
int ultraSoundSignalL = 34; // Ultrasound signal pin
unsigned long ultrasoundValueL = 0;

// W is for west
unsigned long echoW = 0;
int ultraSoundSignalW = 38; // Ultrasound signal pin
unsigned long ultrasoundValueW = 0;

unsigned long echoR = 0;
int ultraSoundSignalR = 32; // Ultrasound signal pin
unsigned long ultrasoundValueR = 0;

// E is for East
unsigned long echoE = 0;
int ultraSoundSignalE = 36; // Ultrasound signal pin
unsigned long ultrasoundValueE = 0;


//      UltraSound Sensor Map
//      Left - West - Front - East - Right
//    pingL - pingW - pingF - pingE - pingR

void setup() 
{
  servoRight.attach(3);  // attaches the servo on pin 3 to the servo object
  servoLeft.attach(4);  // attaches the servo on pin 4 to the servo object
  //linearArm.attach(5);    // x is pin attached on board
  

  Serial.begin(9600);
  pinMode(ultraSoundSignalF,OUTPUT);
  pinMode(ultraSoundSignalW,OUTPUT);
  pinMode(ultraSoundSignalE,OUTPUT);
  pinMode(ultraSoundSignalL,OUTPUT);
  pinMode(ultraSoundSignalR,OUTPUT);
}


// Set Linear Arm to extend or contract by percentage of arm length
void SetStrokePerc(float strokePercentage)
{
  if ( strokePercentage >= 1.0 && strokePercentage <= 99.0 )
  {
    int usec = 1000 + strokePercentage * ( 2000 - 1000 ) / 100.0 ;
    linearArm.writeMicroseconds( usec );
  }
}

// Call the requested length and max length allowed
void SetStrokeMM(int strokeReq,int strokeMax)
{
  SetStrokePerc( ((float)strokeReq) / strokeMax );
}


unsigned long pingF()
{ 
  pinMode(ultraSoundSignalF, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignalF, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignalF, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignalF, LOW); // Holdoff
  pinMode(ultraSoundSignalF, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignalF, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
  echoF = pulseIn(ultraSoundSignalF, HIGH); //Listen for echo
  ultrasoundValueF = (echoF / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValueF;
}


unsigned long pingL()
{ 
  pinMode(ultraSoundSignalL, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignalL, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignalL, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignalL, LOW); // Holdoff
  pinMode(ultraSoundSignalL, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignalL, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
  echoL = pulseIn(ultraSoundSignalL, HIGH); //Listen for echo
  ultrasoundValueL = (echoL / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValueL;
}


unsigned long pingR()
{ 
  pinMode(ultraSoundSignalR, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignalR, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignalR, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignalR, LOW); // Holdoff
  pinMode(ultraSoundSignalR, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignalR, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
  echoR = pulseIn(ultraSoundSignalR, HIGH); //Listen for echo
  ultrasoundValueR = (echoR / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValueR;
}

unsigned long pingW()
{ 
  pinMode(ultraSoundSignalW, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignalW, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignalW, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignalW, LOW); // Holdoff
  pinMode(ultraSoundSignalW, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignalW, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
  echoW = pulseIn(ultraSoundSignalW, HIGH); //Listen for echo
  ultrasoundValueW = (echoW / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValueW;
}

unsigned long pingE()
{ 
  pinMode(ultraSoundSignalE, OUTPUT); // Switch signalpin to output
  digitalWrite(ultraSoundSignalE, LOW); // Send low pulse 
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(ultraSoundSignalE, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(ultraSoundSignalE, LOW); // Holdoff
  pinMode(ultraSoundSignalE, INPUT); // Switch signalpin to input
  digitalWrite(ultraSoundSignalE, HIGH); // Turn on pullup resistor
  // please note that pulseIn has a 1sec timeout, which may
  // not be desirable. Depending on your sensor specs, you
  // can likely bound the time like this -- marcmerlin
  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
  echoE = pulseIn(ultraSoundSignalE, HIGH); //Listen for echo
  ultrasoundValueE = (echoE / 58.138) * .39; //convert to CM then to inches
  return ultrasoundValueE;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// this is an array that the robot will map within.
// 0's are free space and 1's are objects and walls.
int mapping [10] [15] = { 
  {    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1    }
  ,
  {    1,0,0,0,0,0,0,0,0,0,0,0,1,0,1    }
  ,
  {    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1    }
  ,
  {    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1    }
  ,
  {    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1    }
  ,
  {    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1    }
  ,
  {    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1    }
  ,
  {    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1    }
  ,
  {    1,0,0,0,0,0,0,0,0,0,0,0,0,0,1    }
  ,
  {    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1    }
};


// robot location
// 0 is up
// 1 is right
// 2 is down
// 3 is left
int robotDirection = 2;


// coordinates in the grid of where the robot is
// x and y indexes in the mapping array.
int xcoordinate = 2;
int ycoordinate = 1;


// Check the Grid of the space right in front of it.
int getFrontNumber() 
{
  if (robotDirection == 0) {
    return mapping  [ycoordinate - 1][xcoordinate];
  }
  if (robotDirection == 1)  {
    return mapping  [ycoordinate][xcoordinate + 1];
  }
  if (robotDirection == 2) {
    return mapping [ycoordinate + 1][xcoordinate] ;
  }
  if (robotDirection == 3) {
    return mapping  [ycoordinate][xcoordinate - 1];
  }
}


// Check the Grid of the space to the Right of it.
int getRightNumber() 
{
  if (robotDirection == 0) {
    return mapping [ycoordinate][xcoordinate + 1] ;

  }
  if (robotDirection == 1)  {
    return mapping  [ycoordinate + 1][xcoordinate];

  }
  if (robotDirection == 2) {
    return mapping  [ycoordinate][xcoordinate - 1];
  }
  if (robotDirection == 3) {
    return mapping  [ycoordinate - 1][xcoordinate];
  }
}


// Check the Grid of the Space to the Left of it.
int getLeftNumber() 
{
  if (robotDirection == 0) {
    return mapping [ycoordinate][xcoordinate - 1] ;
  }
  if (robotDirection == 1)  {
    return mapping  [ycoordinate - 1][xcoordinate];
  }
  if (robotDirection == 2) {
    return mapping [ycoordinate][xcoordinate + 1] ;
  }
  if (robotDirection == 3) {
    return mapping  [ycoordinate + 1][xcoordinate];
  }
}


// Checks if there is something right in front of it using Grids
boolean isFrontOpen() 
{
  int nextNumber = getFrontNumber();
  if (nextNumber == 0){
    return true;
  }
  else {
    return false;
  }
}


// Checks if there is something to the Right of it using Grids
boolean isRightOpen()
{
  int nextNumber = getRightNumber();
  if (nextNumber == 0){
    return true;
  }
  else {
    return false;
  }
}


// Checks if there is something to the Left of it using Grids
boolean isLeftOpen()
{
  int nextNumber = getLeftNumber();
  if (nextNumber == 0){
    return true;
  }
  else {
    return false;
  }
}



void forward() 
{
  servoLeft.write(180);
  servoRight.write(0);

  Serial.println("Forward");
  if (robotDirection == 0)
    ycoordinate = ycoordinate - 1;
  if (robotDirection == 1)
    xcoordinate = xcoordinate + 1;
  if (robotDirection == 2)
    ycoordinate = ycoordinate + 1;
  if (robotDirection == 3)
    xcoordinate = xcoordinate - 1;
  delay (100);
  
  delay (800);
  //servoLeft.write(120);   old speed range
  //servoRight.write(60);
  //delay (400);
}

void turnAround() 
{
  servoLeft.write(90);
  servoRight.write(90);
  delay(400);
  Serial.println("Around");
  if (robotDirection == 0)
    robotDirection = 2;
  else if (robotDirection == 1)
    robotDirection = 3;
  else if (robotDirection == 2)
    robotDirection = 0;
  else if (robotDirection == 3)
    robotDirection = 1;
  delay (500);
  Serial.print("  xcoordinate " );
  Serial.print(xcoordinate);
  delay (500);
  Serial.print(" ycoordinate ");
  Serial.print(ycoordinate);
  delay (500);
  Serial.print("  robot direction: ");
  Serial.print(robotDirection);
  delay(500);
  Serial.println();

  delay(1000);
  //servoLeft.write(60);    old speed range
  //servoRight.write(120);
  //delay (400);
}


void turnLeft() 
{
  servoLeft.write(60);
  servoRight.write(60);
  delay(325);
  servoRight.write(95) ;
  delay(65) ;
  servoLeft.write(90);
  Serial.println("Left");
  if (robotDirection == 0)
    robotDirection = 3;
  else if (robotDirection == 1)
    robotDirection = 0;
  else if (robotDirection == 2)
    robotDirection = 1;
  else if (robotDirection == 3)
    robotDirection = 2;
  delay (500);
  Serial.print("  xcoordinate " );
  Serial.print(xcoordinate);
  delay (500);
  Serial.print(" ycoordinate ");
  Serial.print(ycoordinate);
  delay (500);
  Serial.print("  robot direction: ");
  Serial.print(robotDirection);
  delay(500);
  Serial.println();
  delay(1000);
  //servoLeft.write(60);    old speed range
  //servoRight.write(60);
  //delay(400)
}


void turnRight() 
{
  servoLeft.write (120);
  servoRight.write (120);
  delay(178);
  servoRight.write(95) ;
  delay(65) ;
  servoLeft.write(90);
  Serial.println("Right");
  if (robotDirection == 0)
    robotDirection = 1;
  else if (robotDirection == 1)
    robotDirection = 2;
  else if (robotDirection == 2)
    robotDirection = 3;
  else if (robotDirection == 3)
    robotDirection = 0;
  delay (500);
  Serial.print("  xcoordinate " );
  Serial.print(xcoordinate);
  delay (500);
  Serial.print(" ycoordinate ");
  Serial.print(ycoordinate);
  delay (500);
  Serial.print("  robot direction: ");
  Serial.print(robotDirection);
  delay (500);
  Serial.println();

  delay(1000);
  //servoLeft.write(120);   old speed range
  //servoRight.write(120);
  //delay(400);
}

void halt() 
{
  servoLeft.detach();
  servoRight.detach();
}


void shutDown() 
{
  exit(0);
}

// Tweak the variables ‘d’ and ‘delayMS’ to get a feel for how the actuator works.
void moveLinearArm()
{
  int d = 10;
  int delayMS = 1500;
  int i = 0;
  for ( i = 1; i < 99; i += d )
  {
    SetStrokePerc(i);
    delay(delayMS);
  }
  for ( i = 99; i > 1;  i -= d )
  {
    SetStrokePerc(i);
    delay(delayMS);
  }
}

//Move Robot left or right to get better light source
void trackLight()
{
  int photoLeft = analogRead(photoL);
  int photoRight = analogRead(photoR);
  delay(200);

  if (photoLeft < photoRight)
  {
    servoLeft.write(60);
    delay(100);
    if(photoLeft > photoRight) halt();
  }
  else
  {
    servoLeft.write(120);
    delay(100);
    if(photoLeft < photoRight) halt();
  }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void loop()
{
  //photodiode activation
  int photoRead = analogRead(photoD);

  Serial.print(photoRead);

  //Ultrasonic ping initialized.  Ping() == Distance in inches.
  int f,l,r,w,e = 0;
  f = pingF();
  l = pingL();
  r = pingR();
  w = pingW();
  e = pingE();
  
    //   when the ultrasound sensor is too close to the wall,
    //   it throws extreme values that are less than 4 && greater 130

  while (1==1)
  {
    // When the robot finds a light source of photoRead intensity, Stop.
    if(photoRead > 40){
      trackLight();
      moveLinearArm();
      
      delay(10000);
      shutDown();
    }

    // Checks the map, and travels through all free space.
    // The robot will divert if the Ultrasonic sensors detect objects in the way.
    if (isFrontOpen() == true) {
      forward();
      delay (2000);
    }
    else if (isRightOpen() == true || (f < 10 && l < 10 && r > 10 && w < 10 && e > 10) ) {
      turnRight();
      delay (2000);
    }
    else if (isLeftOpen() == true || (f < 10 && l > 10 && r < 10 && w > 10 && e < 10) ) {
        turnLeft();
        delay (2000);
    } 
    else if ( isFrontOpen(),isRightOpen(),isLeftOpen() == false 
          ||  (f < 12 && l < 12 && r < 12 && w < 12 && e < 12) ) 
        {
            turnAround();
            delay (2000);
        }
  }

}
