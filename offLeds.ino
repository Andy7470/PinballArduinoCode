void offLeds(){
  if (currentTime - lastOff >= 1000){
  for(int i=36; i <= 45; i++){
    digitalWrite(i,LOW); 
  }
  }
}
