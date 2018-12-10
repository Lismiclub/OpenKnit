/**
 * Knit scarfs, beanies, dresses (no sleeves), socks, etc
 * @param width: Width of the scarf, measured in encoder ticks
 * @param height: Height of the scarf, measured in knitted rows
 * @param offset: Offset at the start, measured in encoder ticks
 */
void tube(int width, int height, int offset) {
  int hotPhase = 132;
  
  int startForward = offset;
  int endForward = startForward + width;
  int startBackward = endForward + hotPhase;
  int endBackward = startForward + hotPhase;
  
  for (int i = 0; i < height; i++) {
    delay(10);
    
    servosNoneFront();
    goForwardTo(startForward);

    servosFront();
    goForwardTo(endForward);
    
    servosNoneFront();
    goForwardTo(startBackward);
    
    servosBack();
    goBackwardTo(endBackward);
    
    servosNoneBack();
    goBackwardTo(0);
  }
}

void goForwardTo(int endpoint) {
  setDirectionForward();

  while (encoderValue < endpoint) {
    moveOneStep();
  }
}

void goBackwardTo(int endpoint) {
  setDirectionBackward();

  while(encoderValue > endpoint) {
    moveOneStep();
  }
}


