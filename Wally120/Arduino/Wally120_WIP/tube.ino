/**
 * Knit scarfs, beanies, dresses (no sleeves), socks, etc
 * @param width: Width of the scarf, measured in encoder ticks
 * @param height: Height of the scarf, measured in knitted rows
 * @param offset: Offset at the start, measured in encoder ticks
 */
void tube(int width, int height, int offset) {
  int shift = 130;

  int startForward = 128;
  int endForward = 483;
  int startBackward = endForward + shift;
  int endBackward = startForward + shift - 3;


  servosNoneFront();
  goForwardTo(startForward);

  for (int i = 0; i < height; i++) {
    servosFront();
    goForwardTo(endForward);

    servosNoneFront();
    goForwardTo(startBackward);

    servosBack();
    goBackwardTo(endBackward);

    servosNoneBack();
    goBackwardTo(startForward);
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
