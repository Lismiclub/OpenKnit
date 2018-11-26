// brings carriage to the rightmost, needle 0

void homing() {
  readEndStop();

  setDirectionBackward();
  
  while (!endStopActive)       
  {
    moveOneStep();
  }
  servosNoneBack();
} 

void readEndStop() {
  endStopActive = (digitalRead(endStopPin) == HIGH);
}
