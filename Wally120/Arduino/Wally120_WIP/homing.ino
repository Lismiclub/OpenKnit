// brings carriage to the rightmost, needle 0

void homing() {
  readEndStop();

  servosNoneBack();
  setDirectionBackward();
  
  while (!endStopActive)       
  {
    moveOneStep();
  }
} 

void readEndStop() {
  endStopActive = (digitalRead(endStopPin) == HIGH);
}
