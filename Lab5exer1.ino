#include <SPI.h> 
#define Data_pin 11
#define Clock_pin 13
#define SS_pin1 10
#define SS_pin2 9

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
  SPI.begin();
  SPI.beginTransaction(SPISettings(14000000,MSBFIRST,SPI_MODE0));
}

void loop()
{
  for(int j=0; j<=99; j++){
      dis_num(j);
      delay(1000);
  }    
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
