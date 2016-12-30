#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

static unsigned char PROGMEM logo16_glcd_bmp[] =
{
  B00000000, B00000000,
  B00011000, B00011000,
  B00111100, B00111100,
  B01111110, B01111110,
  B11111111, B11111111,
  B11111111, B11111111,
  B11111111, B11111111,
  B01111111, B11111110,
  B00111111, B11111100,
  B00011111, B11111000,
  B00001111, B11110000,
  B00000111, B11100000,
  B00000011, B11000000,
  B00000001, B10000000,
  B00000000, B00000000,
  B00000000, B00000000
 };
 
int portSpeak(3);  //porta ligada no speaker 
int melodia[] = {660,660,660,510,660,770,380,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,510,380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,480,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,760,720,680,620,650,380,430,500,430,500,570,500,760,720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,570,585,550,500,380,500,500,500,500,500,500,500,580,660,500,430,380,500,500,500,500,580,660,870,760,500,500,500,500,580,660,500,430,380,660,660,660,510,660,770,380};
int duracaodasnotas[] = {100,100,100,100,100,100,100,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,60,80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,60,80,60,80,80,80,80,80,80,100,100,100,100,100,100,100};
int pausadepoisdasnotas[] = {150,300,300,100,300,550,575,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,450,400,500,300,330,150,300,200,200,150,300,150,350,300,150,150,500,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,300,100,150,150,300,300,150,150,300,150,100,220,300,100,150,150,300,300,300,150,300,300,300,100,150,150,300,300,150,150,300,150,100,420,450,420,360,300,300,150,300,150,300,350,150,350,150,300,150,600,150,300,350,150,150,550,325,600,150,300,350,150,350,150,300,150,600,150,300,300,100,300,550,575};

void passoEsquerda(int tempo)
{
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  
  digitalWrite(4, HIGH);
  delay(tempo);
  digitalWrite(4, LOW);
}

void passoDireita(int tempo)
{
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  
  digitalWrite(4, HIGH);
  delay(tempo);
  digitalWrite(4, LOW);
}

void setup()   {
  Serial.begin(9600);
  
  //Portas do braco eletronico
  pinMode(4, OUTPUT);   
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  //Retornando o carro
  //passoDireita(70);
  
  display.begin();  
  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(40);
  display.clearDisplay();   // clears the screen and buffer

  delay(500);
  //liga o LCD
  analogWrite(7, 200);

  //Inicio das mensagens
 
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Oi meu BB!\nBO-NI-TA!\n\nDeu trabalho, mas saiu! =D");
  display.display();
  delay(3000);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Queria te\nfazer um\nconvite.\n\n\"Possasser\"?");
  display.display();
  delay(4000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Quer iniciar\numa aventura\nComigo?");
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,34);
  display.println("@-'--");
  display.display();
  delay(4000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Jogaremos\nsempre no\ncooperativo.\n    \\o/\\o/\n  (Eh tim!)");
  display.display();
  delay(2000);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Escalaremos,\nNadaremos,\nViajaremos e\nViveremos\n\nSempre...");
  display.display();
  delay(4000);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("JUNTOS!  S2\n 4ever");
  display.display();
  delay(3000);
  
  display.clearDisplay();
  display.setTextSize(6);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("42");
  display.display() ;
  delay(4000);
  
   //Desenha o coracao
  display.clearDisplay();
  display.drawBitmap(32, 16,  logo16_glcd_bmp, 16, 16, 1);
  display.display();
  delay(2000);

  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(4,34);
  display.println("   TE AMO   ");
  display.display();
  delay(3000);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("<her name>,");
  display.display();
  delay(2000);
  
  testdrawline();

  //42
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Quer ser minha");
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println("   Player 2?  ");
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.println("@'-- 42");
  display.display();
  delay(1000);  

 
 //Mostra a alianca =D
 passoEsquerda(100); 

}


void loop() {  
  
   //Tocando a musiquinha

  for (int nota = 0; nota < 156; nota++) {

    int duracaodanota = duracaodasnotas[nota];
    tone(portSpeak, melodia[nota],duracaodanota);
    
    delay(pausadepoisdasnotas[nota]);
  }
  
}


void testfilltriangle(void) {
  uint8_t color = BLACK;
  for (int16_t i=min(display.width(),display.height())/2; i>0; i-=5) {
    display.fillTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
  }
}


void testdrawline() {  
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, BLACK);
    display.display();
  }
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, BLACK);
    display.display();
  }
  delay(250);
  
  display.clearDisplay();
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, BLACK);
    display.display();
  }
  for (int8_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, BLACK);
    display.display();
  }
  delay(250);
  
  display.clearDisplay();
  for (int16_t i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, BLACK);
    display.display();
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, BLACK);
    display.display();
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, BLACK);
    display.display();
  }
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, BLACK); 
    display.display();
  }
  delay(250);
}

