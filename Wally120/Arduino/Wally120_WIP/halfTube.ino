void halfTube(int forward_stop_knit) {
  int turnaround = forward_stop_knit + 135;
  
  while (numberRows < 100) {
    delay(10);

    servosFront();
    goForwardTo(forward_stop_knit);
    
    servosNoneFront();
    goForwardTo(turnaround);
    
    servosBack();
    goBackwardTo(0);
    
    numberRows++;
  }
}

void goForwardTo(int endpoint) {
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  digitalWrite(dir, LOW);

  while (encoderValue < endpoint) {
    moveOneStep();
  }
}

void goBackwardTo(int endpoint) {
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  digitalWrite(dir, HIGH);

  while(encoderValue > endpoint) {
    moveOneStep();
  }
}

void moveOneStep() {
    digitalWrite(steps, HIGH);
    delayMicroseconds(speedRotation / 2);
    digitalWrite(steps, LOW);
    delayMicroseconds(speedRotation / 2);
}


