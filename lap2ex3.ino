int clk_pin = 13; //SHCP 
int latch_pin = 10; //STCP 
int data_pin = 11; //DS 
int potNum = 0;

void setLED(uint16_t state){
  digitalWrite(latch_pin,LOW);
  for(int i = 0 ; i < 16 ; i++){
    digitalWrite(data_pin,(state>>(15-i)) & 0x0001); 
    digitalWrite(clk_pin,HIGH); 
    digitalWrite(clk_pin,LOW); 
  } 
  digitalWrite(latch_pin,HIGH);
}

void setup() {
  
  pinMode(clk_pin,OUTPUT); 
  pinMode(latch_pin,OUTPUT); 
  pinMode(data_pin,OUTPUT);
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT);
}

void loop() { 
  int LB = analogRead(A0);
  int RB = analogRead(A1);
  
  int count=0;
  if(LB < 100 && RB > 100){
    for(int i=0; i<16; i++){
      potNum = analogRead(A2);
      setLED(0b0000000000000001<<count);
      count++;
      delay(potNum); 
    }
  }
  else if(LB > 100 && RB < 100){
    for(int i=0; i<16; i++){
      potNum = analogRead(A2);
      setLED(0b1000000000000000>>count);
      count++;
      delay(potNum);
    }
  }
}
