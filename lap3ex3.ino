int clk_pin = 13; //SHCP 
int latch_pin = 10; //STCP 
int data_pin = 11; //DS
int count = 0; 
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

void setLed(uint8_t _state){
  for(int i=0;i<8;i++){
    digitalWrite(data_pin,(_state>>(7-i))&0x01);
    digitalWrite(clk_pin,HIGH);
    digitalWrite(clk_pin,LOW);
    }
  digitalWrite(latch_pin,HIGH);
  delay(200);
  digitalWrite(latch_pin,LOW);
  }

void setup()
{
  pinMode(clk_pin, OUTPUT);
  pinMode(latch_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
}

void loop()
{
  if(PINC == 0x01)
    count++;
  if(PINC == 0x02)
    count--;
  if(count < 0)
    count = 9;
  if(count > 9)
    count = 0;
  setLed(map7seg[count]);
}
