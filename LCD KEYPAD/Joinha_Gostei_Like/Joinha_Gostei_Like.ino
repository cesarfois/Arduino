/*
 * NAME: LIKE, GOSTEI, JOINHA
 * SHIELD USED : LCD KEYPAD 16x2
 * Credits CREATION: JO3RI : http://www.jo3ri.be/
 *
 * MODIFIED AND SHARED:  César J. Fois https://cesarfois.github.io/
 * Versão: 20 11 2018
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
  lcd.begin(16,2);
  // clear the LCD screen:
  lcd.clear();
}


void loop() {
  // start the Thumbs Up part:
  thumbsup();
}    

void thumbsup() {
 byte thumb1[8] = {B00100,B00011,B00100,B00011,B00100,B00011,B00010,B00001};
 byte thumb2[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00011};
 byte thumb3[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00001,B11110};
 byte thumb4[8] = {B00000,B01100,B10010,B10010,B10001,B01000,B11110,B00000};
 byte thumb5[8] = {B00010,B00010,B00010,B00010,B00010,B01110,B10000,B00000};
 byte thumb6[8] = {B00000,B00000,B00000,B00000,B00000,B10000,B01000,B00110};
 lcd.createChar(8, thumb1);
 lcd.createChar(1, thumb2);
 lcd.createChar(2, thumb3);
 lcd.createChar(3, thumb4);
 lcd.createChar(4, thumb5);
 lcd.createChar(5, thumb6);
 lcd.setCursor(4,1);
 lcd.write(8);
 lcd.setCursor(4,0);
 lcd.write(1);
 lcd.setCursor(5,1);
 lcd.write(2);
 lcd.setCursor(5,0);
 lcd.write(3);
 lcd.setCursor(6,1);
 lcd.write(4);
 lcd.setCursor(6,0);
 lcd.write(5);
}
