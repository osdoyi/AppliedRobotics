#include <Stepper.h>
#include <Servo.h>


Servo pitch;  // create a servo object
Servo roll;  // create a servo object
Servo yaw;  // create a servo object
Servo bag;  // create a servo object

int pos = 90;
int poss;
// ************ Document what has been added in sections
//********** 1) originPosition ::: this zero and finds xMin and yMin for the area
//**** 2) maxPosition:: find xMax and yMax in step size
// **** bool xyMove::: moves the steppers to given xy step position and direction
const int x_pin1 = 22; // +PLS Pin1
const int x_pin2 = 24; // -PLS Pin2
const int x_pin3 = 26; // +DIR Pin3
const int x_pin4 = 28; // -DIR Pin4

const int y_pin1 = 30;
const int y_pin2 = 32;
const int y_pin3 = 34;
const int y_pin4 = 36;

const int frontLimit = 44;
const int leftLimit = 48;
const int backLimit = 50;
const int rightLimit = 46;

int frontState = 0;// variable for reading the pushbutton status
int leftState = 0;
int backState = 0;
int rightState = 0;

const int waitPin = 52;
int waitState;

int stepSpeed = 500; // current step speed in microseconds
int stepSize = 40;
int stepCount = 0;

// strings will be recorded inside this variable when we receive from bluetooth
char joyNow ;
//String upComingDataString = "000,000";

void setup() {

  pitch.attach(11);
  yaw.attach(3);
  roll.attach(10);
  bag.attach(9);
  
  pinMode(x_pin1, OUTPUT);
  pinMode(x_pin2, OUTPUT);
  pinMode(x_pin3, OUTPUT);
  pinMode(x_pin4, OUTPUT);
  pinMode(y_pin1, OUTPUT);
  pinMode(y_pin2, OUTPUT);
  pinMode(y_pin3, OUTPUT);
  pinMode(y_pin4, OUTPUT);

  pinMode(frontLimit, INPUT);
  pinMode(leftLimit, INPUT);
  pinMode(backLimit, INPUT);
  pinMode(rightLimit, INPUT);

  pinMode(waitPin, INPUT);
  
 
  
  Serial.begin(9600);
  Serial1.begin(9600);
      
}



void loop() {

  if (Serial1.available() > 0 )
  {
    
    joyNow = Serial1.read();

    
    // say what you got:
     Serial.print("I received: ");
     Serial.println(joyNow);
    // delay 10 milliseconds to allow Serial update time
    delay(10);

    if (joyNow == 'i'){
    digitalWrite(y_pin3, LOW);
    digitalWrite(y_pin4, HIGH);
    int test_i = 0;
    joyNow = Serial1.read();

      while(stepCount <= stepSize){
      digitalWrite(y_pin1,HIGH);
      delayMicroseconds(stepSpeed);
      digitalWrite(y_pin1,LOW);
      stepCount ++;
    }
    stepCount = 0; 
    }
    
   else if (joyNow == 'k'){
    digitalWrite(y_pin3, HIGH);
    digitalWrite(y_pin4, LOW);
    joyNow = Serial1.read();

      while(stepCount <= stepSize){
      digitalWrite(y_pin1,HIGH);
      delayMicroseconds(stepSpeed);
      digitalWrite(y_pin1,LOW);
      stepCount ++;
    }
    stepCount = 0;
      }
    
  else if (joyNow == 'j'){
    digitalWrite(x_pin3, HIGH);
    digitalWrite(x_pin4, LOW);
    joyNow = Serial1.read();

      while(stepCount <= stepSize){
      digitalWrite(x_pin1,HIGH);
      delayMicroseconds(stepSpeed);
      digitalWrite(x_pin1,LOW);
      stepCount ++;
    }
    stepCount = 0;
      }
         
  else if (joyNow == 'l'){
    digitalWrite(x_pin3, LOW);
    digitalWrite(x_pin4, HIGH);       
    joyNow = Serial1.read();

      while(stepCount <= stepSize){
      digitalWrite(x_pin1,HIGH);
      delayMicroseconds(stepSpeed);
      digitalWrite(x_pin1,LOW);
      stepCount ++;
    }
    stepCount = 0;
      }

   else if (joyNow == 't'){
    pitch.write(70);
   }


   else if (joyNow == 'y'){
    for (pos = 98; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    pitch.write(pos);  
    //delay(1);
   }
   }
   else if (joyNow == 'p'){

     for (poss = 105; poss <= 140; poss += 1) { // goes from 180 degrees to 0 degrees
    pitch.write(poss);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
    //pitch.write(140);
    delay(50);
    roll.write(60);
    delay(50);
    for (poss = 85; poss >= 17; poss -= 1) { // goes from 180 degrees to 0 degrees
    yaw.write(poss);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
    
    dropFish();
   }

   else if (joyNow == 'x'){
    roll.write(65);
   }
   else if (joyNow == 'z'){
    roll.write(130);
   }

   else if (joyNow == 'r'){
     for (pos = 90; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    yaw.write(pos);              // tell servo to go to position in variable 'pos'
                         // waits 15ms for the servo to reach the position
  }
   }
   else if (joyNow == 'e'){
   for (pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    yaw.write(pos);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
  }
   }
   else{
    
    pitch.write(98);
    
    yaw.write(85);
    roll.write(90);
   }
   }
}









