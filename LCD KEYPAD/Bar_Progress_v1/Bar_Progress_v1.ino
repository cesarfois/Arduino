/*
 * NAME: SIMPLE BAR PROGRESS VERSION I
 * SHIELD USED : LCD KEYPAD 16x2
 * Credits CREATION: JO3RI : https://www.carnetdumaker.net/
 *
 * MODIFIED AND SHARED:  César J. Fois https://cesarfois.github.io/
 * Versão: 20 11 2018
 * 
 */




/*Inclui biblioteca LiquidCrystal para LCD */
#include <LiquidCrystal.h>


/* Cria o objeto lcd com uma configuração de pinos compatível com o escudo LCD DFRobots */
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


/* Constantes para o tamanho da tela LCD */
const int LCD_NB_ROWS = 2;
const int LCD_NB_COLUMNS = 16;

/* Caracteres personalizados */
byte DIV_0_OF_5[8] = {
  B00000, 
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
}; // 0 / 5

byte DIV_1_OF_5[8] = {
  B10000, 
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
}; // 1 / 5

byte DIV_2_OF_5[8] = {
  B11000, 
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
}; // 2 / 5 

byte DIV_3_OF_5[8] = {
  B11100, 
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
}; // 3 / 5

byte DIV_4_OF_5[8] = {
  B11110, 
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
}; // 4 / 5

byte DIV_5_OF_5[8] = {
  B11111, 
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
}; // 5 / 5


/**
 *Função de configuração da tela LCD para a barra de progresso.
 * Usa caracteres personalizados de 0 a 5 (6 e 7 permanecem disponíveis).
 */
void setup_progressbar() {

  /* Salva caracteres personalizados na memória da tela LCD */
  lcd.createChar(0, DIV_0_OF_5);
  lcd.createChar(1, DIV_1_OF_5);
  lcd.createChar(2, DIV_2_OF_5);
  lcd.createChar(3, DIV_3_OF_5);
  lcd.createChar(4, DIV_4_OF_5);
  lcd.createChar(5, DIV_5_OF_5);
}
/**
 * Fonction dessinant la barre de progression.
 *
 * @param percent A porcentagem a ser exibida.
 */
void draw_progressbar(byte percent) {

  /* Exibe o novo valor numericamente na primeira linha */
  lcd.setCursor(0, 0);
  lcd.print(percent);
  lcd.print(F(" %  "));
  // N.B. Les deux espaces en fin de ligne permettent d'effacer les chiffres du pourcentage
  // précédent quand on passe d'une valeur à deux ou trois chiffres à une valeur à deux ou un chiffres.

  /* Mova o cursor para a segunda linha*/
  lcd.setCursor(0, 1);

  /* Mapeie o intervalo (0 ~ 100) para o intervalo (0 ~ LCD_NB_COLUMNS * 5) */
  byte nb_columns = map(percent, 0, 100, 0, LCD_NB_COLUMNS * 5);

  /* Dessine chaque caractère de la ligne */
  for (byte i = 0; i < LCD_NB_COLUMNS; ++i) {

    /* Com base no número de colunas restantes para exibir */
    if (nb_columns == 0) { // Case vide
      lcd.write((byte) 0);

    } else if (nb_columns >= 5) { // Case pleine
      lcd.write(5);
      nb_columns -= 5;

    } else { // Derniére case non vide
      lcd.write(nb_columns);
      nb_columns = 0;
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
    //Retorna para zero se a porcentagem exceder 100%
    percent = 0;
    delay(1000);
  }

  /* Tempo de espera curto*/
  delay(100);
}
