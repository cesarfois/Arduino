/*
 * NAME: OPEN AND CLOSED
 * SHIELD USED : 4 Modules Display Max7219 Led 8x8 
 * Credits CREATION: César J. Fois
 *
 * MODIFIED AND SHARED:  César J. Fois https://cesarfois.github.io/
 * Versão: 29 11 2018
 * 
 */


#include <MaxMatrix.h>

int DIN = 9;   // DIN pin of MAX7219 module
int CS = 8;    // CS pin of MAX7219 module
int CLK = 7;   // CLK pin of MAX7219 module
int maxInUse = 4;
int vel = 10;


MaxMatrix m(DIN, CS, CLK, maxInUse); 


void setup() {
  m.init(); // MAX7219 initialization
  m.setIntensity(2); // initial led matrix intensity, 0-15
}

void loop() {
int c1 = 0;
int c2 = 31;
int c3 = 7;  

m.clear(); // Clears the display
 


while (c1 <= 4){
      for (int i=c1; i<=31; i++) {m.setDot(i,c1,true);    delay(vel); }
      for (int i=c1; i<=c3; i++)  {m.setDot(c2,i,true);   delay(vel); }
      for (int i=c2; i>=c1; i--) {m.setDot(i,c3,true);    delay(vel); }
      for (int i=c3; i>=c1; i--)  {m.setDot(c1,i,true);    delay(vel); }
      c1++;
      c2--;
      c3--;
}

//========================================================================================

      for (int i=3;  i<=28; i++)     {m.setDot(i,4,false);     delay(vel);  }   //horizontal   
      for (int i=28; i>=3;  i--)     {m.setDot(i,3,false);     delay(vel);  }   //horizontal 
      for (int i=3;  i<=5;  i++)     {m.setDot(2,i,false);     delay(vel);  }   //vertical
      for (int i=3;  i<=28; i++)     {m.setDot(i,5,false);     delay(vel);  }   //horizontal 
      
      for (int i=5;  i>=2;  i--)     {m.setDot(29,i,false);    delay(vel);  }   //vertical  
      for (int i=29; i>=2;  i--)     {m.setDot(i,2,false);     delay(vel);  }   //horizontal 
      for (int i=2;  i<=6;  i++)     {m.setDot(1,i,false);     delay(vel);  }   //vertical
      for (int i=2;  i<=29; i++)     {m.setDot(i,6,false);     delay(vel);  }   //horizontal      
      for (int i=6;  i>=2;  i--)     {m.setDot(30,i,false);    delay(vel);  }   //vertical
      
      for (int i=30; i>=1;  i--)     {m.setDot(i,1,false);     delay(vel);  }   //horizontal 
      for (int i=1;  i<=7;  i++)     {m.setDot(0,i,false);     delay(vel);  }   //vertical
      for (int i=1;  i<=31; i++)     {m.setDot(i,7,false);     delay(vel);  }   //horizontal      
      for (int i=7;  i>=1;  i--)     {m.setDot(31,i,false);    delay(vel);  }   //vertical
      for (int i=31; i>=1;  i--)     {m.setDot(i,0,false);     delay(vel);  }   //horizontal
      

 m.clear(); // Clears the display
   
}
