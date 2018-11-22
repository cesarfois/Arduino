/*
 * NAME: BAR PROGRESS VERSION II
 * SHIELD USED : LCD KEYPAD 16x2
 * Credits CREATION: JO3RI : https://www.carnetdumaker.net/
 *
 * MODIFIED AND SHARED:  César J. Fois https://cesarfois.github.io/
 * Versão: 20 11 2018
 * 
 */



/* Inclui biblioteca LiquidCrystal para tela LCD */
#include <LiquidCrystal.h>


/* Crie o objeto lcd com uma configuração de pinos compatível com o escudo LCD DFRobots */
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


/* Constantes para o tamanho da tela LCD */
const int LCD_NB_ROWS = 2;
const int LCD_NB_COLUMNS = 16;


/* Caracteres personalizados */
byte START_DIV_0_OF_1[8] = {
  B01111, 
  B11000,
  B10000,
  B10000,
  B10000,
  B10000,
  B11000,
  B01111
}; // Char début 0 / 1

byte START_DIV_1_OF_1[8] = {
  B01111, 
  B11000,
  B10011,
  B10111,
  B10111,
  B10011,
  B11000,
  B01111
}; // Char début 1 / 1

byte DIV_0_OF_2[8] = {
  B11111, 
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
}; // Char milieu 0 / 2

byte DIV_1_OF_2[8] = {
  B11111, 
  B00000,
  B11000,
  B11000,
  B11000,
  B11000,
  B00000,
  B11111
}; // Char milieu 1 / 2

byte DIV_2_OF_2[8] = {
  B11111, 
  B00000,
  B11011,
  B11011,
  B11011,
  B11011,
  B00000,
  B11111
}; // Char milieu 2 / 2

byte END_DIV_0_OF_1[8] = {
  B11110, 
  B00011,
  B00001,
  B00001,
  B00001,
  B00001,
  B00011,
  B11110
}; // Char fin 0 / 1

byte END_DIV_1_OF_1[8] = {
  B11110, 
  B00011,
  B11001,
  B11101,
  B11101,
  B11001,
  B00011,
  B11110
}; // Char fin 1 / 1


/**
 * Função de configuração da tela LCD para a barra de progresso.
 * Usa caracteres personalizados de 0 a 6 (7 à esquerda).
 */
void setup_progressbar() {

  /* Salva caracteres personalizados na memória da tela LCD */
  lcd.createChar(0, START_DIV_0_OF_1);
  lcd.createChar(1, START_DIV_1_OF_1);
  lcd.createChar(2, DIV_0_OF_2);
  lcd.createChar(3, DIV_1_OF_2);
  lcd.createChar(4, DIV_2_OF_2);
  lcd.createChar(5, END_DIV_0_OF_1);
  lcd.createChar(6, END_DIV_1_OF_1);
}


/**
 * Função de desenho da barra de progresso.
 *
 * @@param percent A porcentagem a ser exibida.
 */
void draw_progressbar(byte percent) {
 
  /* Exibe o novo valor numericamente na primeira linha */
  lcd.setCursor(0, 0);
  lcd.print(percent);
  lcd.print(F(" %  ")); 
  // N.B. Os dois espaços no final da linha permitem apagar os números da percentagem
  // anterior quando você muda de um valor de dois ou três dígitos para um valor de dois ou um dígito.
 
  /* Mova o cursor para a segunda linha */
  lcd.setCursor(0, 1);
 
  /* Mapeie o intervalo (0 ~ 100) para o intervalo (0 ~ LCD_NB_COLUMNS * 2 - 2) */
  byte nb_columns = map(percent, 0, 100, 0, LCD_NB_COLUMNS * 2 - 2);
  // Chaque caractère affiche 2 barres verticales, mais le premier et dernier caractère n'en affiche qu'une.

  /* Desenhe cada caractere da linha*/
  for (byte i = 0; i < LCD_NB_COLUMNS; ++i) {

    if (i == 0) { // Premiére case

      /* Mostra o caractere inicial com base no número de colunas */
      if (nb_columns > 0) {
        lcd.write(1); // Char début 1 / 1
        nb_columns -= 1;

      } else {
        lcd.write((byte) 0); // Char début 0 / 1
      }

    } else if (i == LCD_NB_COLUMNS -1) { // Derniére case

      /* Exibe o caractere final com base no número de colunas */
      if (nb_columns > 0) {
        lcd.write(6); // Char fin 1 / 1

      } else {
        lcd.write(5); // Char fin 0 / 1
      }

    } else { // Autres cases

      /* Mostra o tanque correto de acordo com o número de colunas */
      if (nb_columns >= 2) {
        lcd.write(4); // Char div 2 / 2
        nb_columns -= 2;

      } else if (nb_columns == 1) {
        lcd.write(3); // Char div 1 / 2
        nb_columns -= 1;

      } else {
        lcd.write(2); // Char div 0 / 2
      }
    }
  }
}
/** Fonction setup() */
void setup(){
 
  /* Inicializa a tela LCD */
  lcd.begin(LCD_NB_COLUMNS, LCD_NB_ROWS);
  setup_progressbar();
  lcd.clear();
}
 

/** Fonction loop() */
void loop(){
 
  /* Valor percentual da barra de progresso */
  static byte percent = 0;
 
  /* Mostra o valor */
  draw_progressbar(percent);

  /* Aumenta a porcentagem */
  if (++percent == 101) {
    // Revient à zéro si le pourcentage dépasse 100%
    percent = 0;
    delay(1000);
  }

  /* Tempo de espera curto */
  delay(100);
}
