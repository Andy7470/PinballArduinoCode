unsigned long thisTime = 0;
unsigned long counting = 0;

void waitingAnimation(){

 if (currentTime - thisTime >= 1000){
    thisTime = currentTime;
    counting += 1;

  switch(counting){
    
  case 1:
    Serial.println("clear");
    disp.clear();
    break;

  case 2:
   disp.set(_P, 3);
   disp.set(_L, 2);
   disp.set(_A, 1);
   disp.set(_Y, 0);

   break;
 
  case 3:
   disp.clear();
    break;

  case 4:
   disp.set(_P, 3);
   disp.set(_1, 2);
   disp.set(_N, 1);
  break;

  case 5:
  disp.clear();
  break;

  case 6:
  disp.set(_B,3);
  disp.set(_A,2);
  disp.set(_L,1);
  disp.set(_L,0);
  break;

  case 7:
  disp.set(_H,3);
  disp.set(_1,2);
  disp.set(_G,1);
  disp.set(_H,0);
  break;
  case 8:
  disp.set(_S,3);
  disp.set(_C,2);
  disp.set(_O,1);
  disp.set(_r,0);
  break;
  
  case 9:
  disp.digit4(record, true);
  break;
  
  default:
  counting = 0;
  break;
 
      }
      
  }
  
}
