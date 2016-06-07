void dropFish(){
  int i = 0;
  int xx = 0;
  int pos = 0;
  int check = 1;
  int drop_stepSpeed = 100;
  int test1 = 0; int test2 = 0; int test3 = 0;
  int xMid = 9205; int yMid = 4177;
  int xCount = 0; int yCount = 0;
  bool xMax = rightLimit;    bool yMin = backLimit;
  xMax = digitalRead(rightLimit);
  yMin = digitalRead(backLimit);
  int dropWait = 0;
    
  if (xMax == true && yMin == true){
    digitalWrite(x_pin3, LOW);
    digitalWrite(x_pin4, HIGH);
    digitalWrite(y_pin3, HIGH);
    digitalWrite(y_pin4, LOW);
    check = 1;  }
    
  if (xMax == true && yMin == false){
    digitalWrite(x_pin3, LOW);
    digitalWrite(x_pin4, HIGH);
    check = 2;  }
    
  if (xMax == false && yMin == true){
    digitalWrite(y_pin3, HIGH);
    digitalWrite(y_pin4, LOW);
    check = 3;  }
        
  while (check != 0){
        
     while (test1 == 0){
      digitalWrite(x_pin1,HIGH);
      digitalWrite(y_pin1,HIGH);
      delayMicroseconds(drop_stepSpeed);
      digitalWrite(x_pin1,LOW);
      digitalWrite(y_pin1,LOW);
      xMax = digitalRead(rightLimit);
      yMin = digitalRead(backLimit);
      if (xMax == false || yMin == false){
        test1 = 1;}}
        
    while(test2 == 0){
      digitalWrite(x_pin1,HIGH);
      delayMicroseconds(drop_stepSpeed);
      digitalWrite(x_pin1,LOW);
      xMax = digitalRead(rightLimit);
      if (xMax == false){
      test2 = 1; }}
      
    while (test3 == 0){
      digitalWrite(y_pin1,HIGH);
      delayMicroseconds(drop_stepSpeed);
      digitalWrite(y_pin1,LOW);
      yMin = digitalRead(backLimit);
      if (yMin == false){
      test3 = 1; }}
   if(xMax == false && yMin == false && dropWait == 0){
    pitch.write(110);
    
    while(xx<2){
    for (pos = 40; pos <= 140; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    bag.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 140; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
    bag.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
     xx++;
    }
    bag.write(140);
    dropWait = 1;
   }

   if (xMax == false && yMin == false && xCount <= xMid && dropWait !=0 ){
    digitalWrite(x_pin3, HIGH);
    digitalWrite(x_pin4, LOW);
    digitalWrite(y_pin3, LOW);
    digitalWrite(y_pin4, HIGH);
    
    while (xCount < xMid && yCount < yMid && xCount < yMid){
      digitalWrite(x_pin1,LOW);
      digitalWrite(y_pin1,LOW);
      delayMicroseconds(drop_stepSpeed);
      digitalWrite(x_pin1,HIGH);
      digitalWrite(y_pin1,HIGH);
      xCount ++; yCount++ ; }
        
    while(xCount >= yMid && xCount < xMid){
      digitalWrite(x_pin1,LOW);
      delayMicroseconds(drop_stepSpeed);
      digitalWrite(x_pin1,HIGH);
      xCount++;
      }
  if (xCount > xMid){
    check = 0;
  }
  
// add bag code and such here    
    check = 0;
    return;
    }
  }

} // end function dropFish()

