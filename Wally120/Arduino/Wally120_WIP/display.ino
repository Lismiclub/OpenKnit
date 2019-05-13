#include <LiquidCrystal.h>


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12, 6, 5, 4, 2);

void setupDisplay() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hello World!");
}

void updateDisplay() {
  if (encoderHasChanged) {
    encoderHasChanged = false;
    lcd.clear();
    lcd.print(encoderValue);
  }
}
