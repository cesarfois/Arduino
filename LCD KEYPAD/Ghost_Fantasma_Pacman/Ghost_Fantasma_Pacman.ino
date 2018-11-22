/*
 * NAME: PACMAN AND GHOST
 * SHIELD USED : LCD KEYPAD 16x2
 * 
 *
 * MODIFIED, CREATED PACMAN GHOST AND SHARED:  César J. Fois https://cesarfois.github.io/
 * PACMAN CREATED USING PROGRAM FROM : https://pplware.sapo.pt/tutoriais/arduino-como-criar-caracteres-especiais/
 * 
 * Credits CREATION ORIGINAL RUNING MAN : JO3RI : https://www.carnetdumaker.net/
 * 
 * Versão: 20-11-2018
 * 
 */


// DEFINE AS DEFINIÇÕES PARA O MODULO LCD
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8,       //RS Display
                  9,       //E ; Enable
                  4,       //Bus
                  5,       //Bus  
                  6,       //Bus
                  7);      //Bus



// setting animation speed (delay between frames)
int x = 200;
// setting time for Man waiting
int y = 5000;

// START setting all the pixel-art
//setting pixels for standing man:
//step 1 of 1:
  byte stepA1[8] = { B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B10101,  B00000};
  byte stepA2[8] = {B00011, B00111,  B01111,  B11001,  B11001,  B11111,  B11111,  B11111};
  byte stepA3[8] = {B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B10101,  B00000};
  byte stepA4[8] = {B11000,  B11100,  B11110,  B10011,  B10011,  B11111,  B11111,  B11111};
  byte stepA5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte stepA6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  
//setting pixels for running man right:
//step 1 of 3:
  byte stepB1[8] = { B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B10101,  B00000};
  byte stepB2[8] = {B00011, B00111,  B01111,  B11001,  B11001,  B11111,  B11111,  B11111};
  byte stepB3[8] = {B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B10101,  B00000};
  byte stepB4[8] = {B11000,  B11100,  B11110,  B10011,  B10011,  B11111,  B11111,  B11111};
  byte stepB5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte stepB6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};

//step 2 of 3
  byte stepC1[8] = {B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B01010,  B00000};
  byte stepC2[8] = {B00011, B00111,  B01111,  B11111,  B11001,  B11111,  B11111,  B11111};
  byte stepC3[8] = {B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B01010,  B00000};
  byte stepC4[8] = {B11000,  B11100,  B11110,  B11111,  B10011,  B11111,  B11111,  B11111};
  byte stepC5[8] ={B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte stepC6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  
  
//step 3 of 3
  byte stepD1[8] = { B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B01010,  B00000};
  byte stepD2[8] = {B00011, B00111,  B01111,  B11001,  B11001,  B11111,  B11111,  B11111};
  byte stepD3[8] = {B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B01010,  B00000};
  byte stepD4[8] = {B11000,  B11100,  B11110,  B10011,  B10011,  B11111,  B11111,  B11111};
  byte stepD5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte stepD6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};

//setting pixels for man slipping right
//step 1 of 3
  byte slipA1[8] = {B11111, B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte slipA2[8] = {B00000,  B00000,  B00011,  B00111,  B01111,  B11111,  B11111,  B11111};
  byte slipA3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte slipA4[8] = {B00000,  B00000,  B11000,  B11100,  B10010,  B10011,  B11111,  B11111};
  byte slipA5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte slipA6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};

//step 2 of 3
  byte slipB1[8] = {B11111, B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte slipB2[8] = {B00000,  B00000,  B00011,  B00111,  B01111,  B11111,  B11111,  B11111};
  byte slipB3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte slipB4[8] = {B00000,  B00000,  B11000,  B11100,  B10010,  B10011,  B11111,  B11111};
  byte slipB5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte slipB6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};

//step 3 of 3
  byte slipC1[8] = {B11111, B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte slipC2[8] = {B00000,  B00000,  B00011,  B00111,  B01111,  B11111,  B11111,  B11111};
  byte slipC3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte slipC4[8] = {B00000,  B00000,  B11000,  B11100,  B10010,  B10011,  B11111,  B11111};
  byte slipC5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte slipC6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};

//setting pixels for man running left
//step 1 of 3
  byte stepE1[8] = {B00000,  B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte stepE2[8] = {B00000,  B00000,  B00011,  B00111,  B01001,  B11001,  B11111,  B00000};
  byte stepE3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte stepE4[8] = {B00000,  B00000,  B11100,  B11110,  B11111,  B11111,  B11111,  B11111};
  byte stepE5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte stepE6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  
//step 2 of 3
  byte stepF1[8] = {B11111,  B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte stepF2[8] = {B00000,  B00000,  B00011,  B00111,  B01111,  B11001,  B11111,  B00000};
  byte stepF3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte stepF4[8] = {B00000,  B00000,  B11100,  B11110,  B11111,  B11111,  B11111,  B11111};
  byte stepF5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte stepF6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  
//step 3 of 3
  byte stepG1[8] = {B11111,  B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte stepG2[8] = {B00000,  B00000,  B00011,  B00111,  B01001,  B11001,  B11111,  B11111};
  byte stepG3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte stepG4[8] = {B00000,  B00000,  B11100,  B11110,  B11111,  B11111,  B11111,  B11111};
  byte stepG5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte stepG6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  
//setting pixels for man slipping left
//step 1 of 3
  byte slipD1[8] = {B11111,  B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte slipD2[8] = {B00000,  B00000,  B00011,  B00111,  B01001,  B11001,  B11111,  B11111};
  byte slipD3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte slipD4[8] = {B00000,  B00000,  B11100,  B11110,  B11111,  B11111,  B11111,  B11111};
  byte slipD5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte slipD6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};

//step 2 of 3
  byte slipE1[8] = {B11111,  B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte slipE2[8] = {B00000,  B00000,  B00011,  B00111,  B01111,  B11001,  B11111,  B11111};
  byte slipE3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte slipE4[8] = {B00000,  B00000,  B11100,  B11110,  B11111,  B11111,  B11111,  B11111};
  byte slipE5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte slipE6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  
//step 3 of 3
  byte slipF1[8] = {B11111,  B11111,  B11111,  B01111,  B00111,  B00011,  B00000,  B00000};
  byte slipF2[8] = {B00000,  B00000,  B00011,  B00111,  B01001,  B11001,  B11111,  B11111};
  byte slipF3[8] = {B11111,  B11111,  B11111,  B11110,  B11100,  B11000,  B00000,  B00000};
  byte slipF4[8] = {B00000,  B00000,  B11100,  B11110,  B11111,  B11111,  B11111,  B11111};
  byte slipF5[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
  byte slipF6[8] = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000};
// END setting all the pixel-art

//setting up basics
void setup() {
 // set up the LCD's number of columns and rows:
 lcd.begin(16,2);
 // clear the LCD screen:
 lcd.clear();
        // get the standing man part on the screen:
        standingMan();
        delay(y);
        lcd.clear();
        }

//putting all the pieces together in a loop:
void loop() {
 // start the Man animation:
          // run to the the right:
          runningManR();
          // slip to the right:
          ManslipR();
          // now run to the left:
          runningManL();
          // slip to the left:
          ManslipL();
}

// START putting al the pixel-art we defined before in his place for each animation part
// standing man animation part
void standingMan(){
  int a = 0;
  int b = a + 1;
  int c = a + 2;
  lcd.createChar(1, stepA1);
  lcd.createChar(2, stepA2);
  lcd.createChar(3, stepA3);
  lcd.createChar(4, stepA4);
  lcd.createChar(5, stepA5);
  lcd.createChar(6, stepA6);
  lcd.setCursor(a,1);
  lcd.write(1);
  lcd.setCursor(a,0);
  lcd.write(2);
  lcd.setCursor(b,1);
  lcd.write(3);
  lcd.setCursor(b,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
}

// running man to the right animation part
void runningManR() {
  for (int a=0;a<11;a+=4){
  int b = a + 1;
  int c = a + 2;
  int d = a + 3;
  int e = a + 4;
  int f = a + 5;
  int g = a + 6;
  lcd.clear();
  lcd.createChar(1, stepB1);
  lcd.createChar(2, stepB2);
  lcd.createChar(3, stepB3);
  lcd.createChar(4, stepB4);
  lcd.createChar(5, stepB5);
  lcd.createChar(6, stepB6);
  lcd.setCursor(b,1);
  lcd.write(1);
  lcd.setCursor(b,0);
  lcd.write(2);
  lcd.setCursor(c,1);
  lcd.write(3);
  lcd.setCursor(c,0);
  lcd.write(4);
  lcd.setCursor(d,1);
  lcd.write(5);
  lcd.setCursor(d,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepC1);
  lcd.createChar(2, stepC2);
  lcd.createChar(3, stepC3);
  lcd.createChar(4, stepC4);
  lcd.createChar(5, stepC5);
  lcd.createChar(6, stepC6);
  lcd.setCursor(c,1);
  lcd.write(1);
  lcd.setCursor(c,0);
  lcd.write(2);
  lcd.setCursor(d,1);
  lcd.write(3);
  lcd.setCursor(d,0);
  lcd.write(4);
  lcd.setCursor(e,1);
  lcd.write(5);
  lcd.setCursor(e,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepB1);
  lcd.createChar(2, stepB2);
  lcd.createChar(3, stepB3);
  lcd.createChar(4, stepB4);
  lcd.createChar(5, stepB5);
  lcd.createChar(6, stepB6);
  lcd.setCursor(d,1);
  lcd.write(1);
  lcd.setCursor(d,0);
  lcd.write(2);
  lcd.setCursor(e,1);
  lcd.write(3);
  lcd.setCursor(e,0);
  lcd.write(4);
  lcd.setCursor(f,1);
  lcd.write(5);
  lcd.setCursor(f,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepD1);
  lcd.createChar(2, stepD2);
  lcd.createChar(3, stepD3);
  lcd.createChar(4, stepD4);
  lcd.createChar(5, stepD5);
  lcd.createChar(6, stepD6);
  lcd.setCursor(e,1);
  lcd.write(1);
  lcd.setCursor(e,0);
  lcd.write(2);
  lcd.setCursor(f,1);
  lcd.write(3);
  lcd.setCursor(f,0);
  lcd.write(4);
  lcd.setCursor(g,1);
  lcd.write(5);
  lcd.setCursor(g,0);
  lcd.write(6);
  delay(x);
  }
}

// slipping man the the right animation part
void ManslipR(){
  int a = 13;
  int b = a + 1;
  int c = a + 2;
  lcd.clear();
  lcd.createChar(1, slipA1);
  lcd.createChar(2, slipA2);
  lcd.createChar(3, slipA3);
  lcd.createChar(4, slipA4);
  lcd.createChar(5, slipA5);
  lcd.createChar(6, slipA6);
  lcd.setCursor(a,1);
  lcd.write(1);
  lcd.setCursor(a,0);
  lcd.write(2);
  lcd.setCursor(b,1);
  lcd.write(3);
  lcd.setCursor(b,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, slipB1);
  lcd.createChar(2, slipB2);
  lcd.createChar(3, slipB3);
  lcd.createChar(4, slipB4);
  lcd.createChar(5, slipB5);
  lcd.createChar(6, slipB6);
  lcd.setCursor(a,1);
  lcd.write(1);
  lcd.setCursor(a,0);
  lcd.write(2);
  lcd.setCursor(b,1);
  lcd.write(3);
  lcd.setCursor(b,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(x);
  lcd.createChar(1, slipC1);
  lcd.createChar(2, slipC2);
  lcd.createChar(3, slipC3);
  lcd.createChar(4, slipC4);
  lcd.createChar(5, slipC5);
  lcd.createChar(6, slipC6);
  lcd.setCursor(a,1);
  lcd.write(1);
  lcd.setCursor(a,0);
  lcd.write(2);
  lcd.setCursor(b,1);
  lcd.write(3);
  lcd.setCursor(b,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(x);
}

// running man to the left animation part
void runningManL(){
  for (int a=16;a>4;a-=4){
  int b = a - 1;
  int c = a - 2;
  int d = a - 3;
  int e = a - 4;
  int f = a - 5;
  int g = a - 6;
  lcd.clear();
  lcd.createChar(1, stepE1);
  lcd.createChar(2, stepE2);
  lcd.createChar(3, stepE3);
  lcd.createChar(4, stepE4);
  lcd.createChar(5, stepE5);
  lcd.createChar(6, stepE6);
  lcd.setCursor(d,1);
  lcd.write(1);
  lcd.setCursor(d,0);
  lcd.write(2);
  lcd.setCursor(c,1);
  lcd.write(3);
  lcd.setCursor(c,0);
  lcd.write(4);
  lcd.setCursor(b,1);
  lcd.write(5);
  lcd.setCursor(b,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepF1);
  lcd.createChar(2, stepF2);
  lcd.createChar(3, stepF3);
  lcd.createChar(4, stepF4);
  lcd.createChar(5, stepF5);
  lcd.createChar(6, stepF6);
  lcd.setCursor(e,1);
  lcd.write(1);
  lcd.setCursor(e,0);
  lcd.write(2);
  lcd.setCursor(d,1);
  lcd.write(3);
  lcd.setCursor(d,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepE1);
  lcd.createChar(2, stepE2);
  lcd.createChar(3, stepE3);
  lcd.createChar(4, stepE4);
  lcd.createChar(5, stepE5);
  lcd.createChar(6, stepE6);
  lcd.setCursor(f,1);
  lcd.write(1);
  lcd.setCursor(f,0);
  lcd.write(2);
  lcd.setCursor(e,1);
  lcd.write(3);
  lcd.setCursor(e,0);
  lcd.write(4);
  lcd.setCursor(d,1);
  lcd.write(5);
  lcd.setCursor(d,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, stepG1);
  lcd.createChar(2, stepG2);
  lcd.createChar(3, stepG3);
  lcd.createChar(4, stepG4);
  lcd.createChar(5, stepG5);
  lcd.createChar(6, stepG6);
  lcd.setCursor(g,1);
  lcd.write(1);
  lcd.setCursor(g,0);
  lcd.write(2);
  lcd.setCursor(f,1);
  lcd.write(3);
  lcd.setCursor(f,0);
  lcd.write(4);
  lcd.setCursor(e,1);
  lcd.write(5);
  lcd.setCursor(e,0);
  lcd.write(6);
  delay(x);
  }
}

// slipping man to the leftt animation part
void ManslipL(){
  int a = 1;
  int b = a + 1;
  int c = a + 2;
  lcd.clear();
  lcd.createChar(1, slipD1);
  lcd.createChar(2, slipD2);
  lcd.createChar(3, slipD3);
  lcd.createChar(4, slipD4);
  lcd.createChar(5, slipD5);
  lcd.createChar(6, slipD6);
  lcd.setCursor(a,1);
  lcd.write(1);
  lcd.setCursor(a,0);
  lcd.write(2);
  lcd.setCursor(b,1);
  lcd.write(3);
  lcd.setCursor(b,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(x);
  lcd.clear();
  lcd.createChar(1, slipE1);
  lcd.createChar(2, slipE2);
  lcd.createChar(3, slipE3);
  lcd.createChar(4, slipE4);
  lcd.createChar(5, slipE5);
  lcd.createChar(6, slipE6);
  lcd.setCursor(a,1);
  lcd.write(1);
  lcd.setCursor(a,0);
  lcd.write(2);
  lcd.setCursor(b,1);
  lcd.write(3);
  lcd.setCursor(b,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(x);
  lcd.createChar(1, slipF1);
  lcd.createChar(2, slipF2);
  lcd.createChar(3, slipF3);
  lcd.createChar(4, slipF4);
  lcd.createChar(5, slipF5);
  lcd.createChar(6, slipF6);
  lcd.setCursor(a,1);
  lcd.write(1);
  lcd.setCursor(a,0);
  lcd.write(2);
  lcd.setCursor(b,1);
  lcd.write(3);
  lcd.setCursor(b,0);
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(5);
  lcd.setCursor(c,0);
  lcd.write(6);
  delay(x);
}