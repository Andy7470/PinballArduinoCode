void gameRunning(){
  disp.digit4showZero(score);
  if (animationStart){

    pointsAnimation();
    playBuzzer(2);
    digitalWrite(takeOut,HIGH);
    delay(400);
    digitalWrite(takeOut,LOW);
    animationStart = 0;
  }
  digitalWrite(flips,HIGH);

// Detection of the scores
  if (digitalRead(points_20) != 1){

    score += 20;
    digitalWrite(points_20L,HIGH);
    playBuzzer(1);
    delay(10);
  }

  if (digitalRead(points2_20)!= 1){
 
    score += 20;
    digitalWrite(points2_20L,HIGH);
    playBuzzer();
    delay(10);
  }
  if (digitalRead(points_30)!= 1){

    score += 30;
    digitalWrite(points_30L,HIGH);
    playBuzzer();
    delay(10);
  }
  if (digitalRead(points_90)!= 1){
  
    score += 90;
    playBuzzer();
    delay(10);
  }
  if (digitalRead(points_50)!= 1){
  
    score += 50;
    playBuzzer();
    delay(10);
  }
  if (digitalRead(points_80)!= 1){
  
    score += 80;
    digitalWrite(points_80L,HIGH);
    playBuzzer();
    delay(10);
  }
  if (digitalRead(points_10)!= 1){
   
    score += 10;
    digitalWrite(points_10L,HIGH);
    playBuzzer();
    delay(10);
  }
  if (digitalRead(points2_10)!= 1){
  
    score += 10;
    digitalWrite(points2_10L,HIGH);
    playBuzzer();
    delay(10);
  }
   
//multiball  
  if (digitalRead(multiballSensor)!= 1){

    balls += 1;
    ballCounter += 1;
    score += 10;
    digitalWrite(takeOut,HIGH);
    delay(500);
    digitalWrite(takeOut,LOW);

    }
  if (balls > 1){

    digitalWrite(multiball,HIGH);
  }
    
  if (score - lastMultiball >= 100){
    lastMultiball = score;
    digitalWrite(multiball,HIGH);
  }


//endGame
  if (digitalRead(endGame)!= 1){

    ballCounter -= 1;
    playBuzzer(2);
    delay(40);
  }

    if (currentTime - lasttimeBuzzer >= 300){
      digitalWrite(buzzer,LOW);
       if (timesb > 1){
         playBuzzer();
         timesb - 1;
        }
     }



    if (ballCounter <= 0){

        disp.digit4showZero(score);
        digitalWrite(buzzer,LOW);
        delay(500);
        game = 0;
        ballCounter = 1;
        animationStart = 1;
        if (score > record){
          record = score;
        }  
        score = 0;
    }

  offLeds();






}
