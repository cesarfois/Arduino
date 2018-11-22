/*
 * NAME: SHOW TEXT
 * SHIELD USED : LCD KEYPAD 16x2 *
 * CREDITS:  César J. Fois https://cesarfois.github.io/
 * Versão: 20-11-2018
 * 
 */


// include the library code:
#include  <LiquidCrystal.h>


// DEFINE AS DEFINIÇÕES PARA O MODULO LCD
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8,       //RS Display
                  9,       //E ; Enable
                  4,       //Bus
                  5,       //Bus  
                  6,       //Bus
                  7);      //Bus

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("BY");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("   CESAR J. FOIS");
}
