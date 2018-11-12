// brings carriage to the rightmost, needle 0

void homing() {
  initEndStop();

  setDirectionBackward();
  
  while (!endStopActive)       
  {
    moveOneStep();
  }
  servosNoneBack();
} 

void initEndStop() {
  endStopActive = (digitalRead(encoderPin1) == HIGH);
}
