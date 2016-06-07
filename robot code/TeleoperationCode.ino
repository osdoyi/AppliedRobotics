/*Batuhan Yapanoglu 2015*/
//ASME Remote Control Arduino Code
#define DEBUG true

//command array for switches
#define NUM_sCMD 7//number of two-way switches


#define FORWARD  0
#define BACKWARD 1
//two-way switches
//FL FR BL BR SMLR SMFB EL
unsigned char sSwitchPins[NUM_sCMD][2]={ {24,25}, {26,27}, {22,23}, {29,28}, {52,53}, {51,50}, {30,31} }; //{forward,backward}
unsigned char butPin = 32;
#define LEFT  0
#define RIGHT 1
#define UP    2
#define DOWN  3
unsigned char motorPins[4] = { 39, 38, 40, 41 }; //left,right,up,down

int joyPinBM = 0;    // joystick pin for back elavations
int joyPinFM = 1;    // joystick pin for forward elavations         
int joyPinGFB = 2;   // joystick pin for go forward backward  
int joyPinGLR = 3;   // joystick pin for go left right
 
 
void setup() {
  if(DEBUG)
    Serial.begin(9600);
  Serial1.begin(9600);
  for(int i = 0; i < NUM_sCMD; i++){
    pinMode(sSwitchPins[i][FORWARD],INPUT);
    pinMode(sSwitchPins[i][BACKWARD],INPUT);
  }
  pinMode(butPin, INPUT);
 
  for(int i = 0; i < 4; i++)
    pinMode(motorPins[i],INPUT);
}

char commander;
char command;
char preCommand;

void loop() {
  
  if(analogRead(joyPinGLR) <= 250 ){
    command = 'j';
  }else if(analogRead(joyPinGLR) >= 750 ){
    command = 'l';
  }else if(analogRead(joyPinGFB) <= 250 ){
    command = 'i';
  }else if(analogRead(joyPinGFB) >= 750 ){
    command = 'k';
  }else if(digitalRead(butPin) == HIGH ){
   commander = 'p';
  }else if(digitalRead(sSwitchPins[0][FORWARD]) == HIGH ){
    command = 'n';
  }else if(digitalRead(sSwitchPins[0][BACKWARD]) == HIGH ){
    command = 'b';
  }else if(digitalRead(sSwitchPins[1][FORWARD]) == HIGH ){
    command = 'h';
  }else if(digitalRead(sSwitchPins[1][BACKWARD]) == HIGH ){
    command = 'g';
  }else if(digitalRead(sSwitchPins[2][FORWARD]) == HIGH ){
    command = 'v';
  }else if(digitalRead(sSwitchPins[2][BACKWARD]) == HIGH ){
    command = 'c';
  }else if(digitalRead(sSwitchPins[3][FORWARD]) == HIGH ){
    command = 'f';
  }else if(digitalRead(sSwitchPins[3][BACKWARD]) == HIGH ){
    command = 'd';
  }else if(analogRead(joyPinFM) >= 750 ){
    command = 'y';
  }else if(analogRead(joyPinFM) <= 250 ){
    command = 't';
  }else if(analogRead(joyPinBM) >= 750 ){
    command = 'r';
  }else if(analogRead(joyPinBM) <= 250 ){
    command = 'e';
  }else if(digitalRead(sSwitchPins[6][FORWARD]) == HIGH){
    command = 'q';
  }else if(digitalRead(sSwitchPins[6][BACKWARD]) == HIGH ){
    command = 'a';
  }else if(digitalRead(sSwitchPins[4][FORWARD]) == HIGH ){
    command = 'x'; 
  }else if(digitalRead(sSwitchPins[4][BACKWARD]) == HIGH ){
    command = 'z'; 
  }else if(digitalRead(sSwitchPins[5][FORWARD]) == HIGH ){
    command = 'm'; 
  }else if(digitalRead(sSwitchPins[5][BACKWARD]) == HIGH ){
    command = 'u';    
  }else{
    command = 's';
    commander = 's';
  }
  
  //send code
 // if(command != preCommand){
    Serial1.write(command);

  if(commander != preCommand){
    Serial1.write(commander);
    preCommand = commander;
   }
 //   preCommand = command;
    if(DEBUG){
      Serial.print(command);
      Serial.println();
    }
    delay(25);
 // }
  
}

