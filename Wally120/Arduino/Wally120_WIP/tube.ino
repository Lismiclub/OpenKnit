
/**
 * Knit scarfs, beanies, dresses (no sleeves), socks, etc
 * @param width: Width of the scarf, measured in encoder ticks
 * @param height: Height of the scarf, measured in knitted rows
 */
void tube(int width, int height) {
  int turnaround = width + 135;
  
  for (int i = 0; i < height; i++) {
    delay(10);

    servosFront();
    goForwardTo(width);
    
    servosNoneFront();
    goForwardTo(turnaround);
    
    servosBack();
    goBackwardTo(0);
  }
}

void goForwardTo(int endpoint) {
  setDirectionForward();

  while (encoderValue < endpoint) {
    updateDisplay();
    moveOneStep();
  }
}

void goBackwardTo(int endpoint) {
  setDirectionBackward();

  while(encoderValue > endpoint) {
    updateDisplay();
    moveOneStep();
  }
}
