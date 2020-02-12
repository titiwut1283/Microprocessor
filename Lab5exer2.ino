#include <SPI.h> 
#define Data_pin 11
#define Clock_pin 13
#define SS_pin1 10
#define SS_pin2 9
#define buzzer 2

int number = 0;
int map7seg[10] = {
    0x3F, //0
    0x06, //1
    0x5B, //2
    0x4F, //3
    0x66, //4
    0x6D, //5
    0x7D, //6
    0x07, //7
    0x7F, //8
    0x6F  //9
};

void setup()
{
  pinMode(SS_pin1, OUTPUT);
  pinMode(SS_pin2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  SPI.begin();
  SPI.beginTransaction(SPISettings(14000000,MSBFIRST,SPI_MODE0));
}

void loop()
{
  int dBot = digitalRead(5);
  int iBot = digitalRead(6);
  int Bot = digitalRead(7);
  if(dBot == 0 && iBot == 1 && Bot == 1){
    number--;
    noTone(buzzer);
    }
  if(dBot == 1 && iBot == 0 && Bot == 1){
    number++;
    noTone(buzzer);
    }
  if(dBot == 1 && iBot == 1 && Bot == 0){
    delay(200);
    for(int i=number; i>=0;i--){
      int counter = digitalRead(7);
      dis_num(i);
      if(counter == 0){
        number = i;
        i=-1;
        }
      delay(200);
      if(i == 0)
        number =0;
      }
    }
  if(number < 0)
    number = 99;
  if(number > 99)
    number = 0;
  if(number== 0)
    tone(buzzer, 500);
  dis_num(number);
  delay(200);    
}

void spi_write1(int i){
    SPI.transfer(map7seg[i]);
    digitalWrite(SS_pin1, HIGH);
    digitalWrite(SS_pin1, LOW);
}

void spi_write2(int i){
    SPI.transfer(map7seg[i]);
    digitalWrite(SS_pin2, HIGH);
    digitalWrite(SS_pin2, LOW);
}
void dis_num(int x)
{
      int x1,x2;
      x1 = x % 10;
      x2 = x/10;
      spi_write2(x1);
      spi_write1(x2);
}
