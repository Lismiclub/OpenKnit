const int FORWARD_KNIT = 1;
const int FORWARD_EMPTY = 2;
const int BACKWARD_KNIT = 3;
const int BACKWARD_EMPTY = 4;

int direction = FORWARD_KNIT;

int FORWARD_STOP_KNIT = 150 + 200;
int TURNAROUND = FORWARD_STOP_KNIT + 135;

void halfTube () {
  while (numberRows < 100) {
    delay(10);

    if (direction == FORWARD_KNIT) {
      servosFront();
      goForward(FORWARD_STOP_KNIT);
      direction = FORWARD_EMPTY;
    }

    if (direction == FORWARD_EMPTY) {
      servosNoneFront();
      goForward(TURNAROUND);
      direction = BACKWARD_KNIT;
    }

    if (direction == BACKWARD_KNIT) {
      servosBack();
      goBackward(0);
      numberRows++;
      direction = FORWARD_KNIT;
    }
  }
}

void goForward(int endpoint) {
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  digitalWrite(dir, LOW);

  for (i = 0; i < stepsRotation; i++) {
    digitalWrite(steps, HIGH);
    delayMicroseconds(speedRotation / 2);
    digitalWrite(steps, LOW);
    delayMicroseconds(speedRotation / 2);
    
    if (encoderValue >= endpoint) {  //limits the movement to the left
      return;
    }
  }
}

void goBackward(int endpoint) {
  digitalWrite(reset, LOW);
  delay(100);
  digitalWrite(reset, HIGH);
  digitalWrite(dir, HIGH);

  for ( i = 0; i < stepsRotation; i++) {
    digitalWrite(steps, HIGH);
    delayMicroseconds(speedRotation / 2);
    digitalWrite(steps, LOW);
    delayMicroseconds(speedRotation / 2);
    
    if (encoderValue <= endpoint) {  //limits the movement to the right
      return;
    }
  }
}




