float brightness = 0;
String buff;
int state;
int port = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if(inByte == 'L'){
      state = 0;
      buff = ' ';
      }
    if(inByte == 'B'){
      state = 1;
      buff = ' ';
      } 
    if(('0'<= inByte) && (inByte <= '9') && (state == 0)){
      if(inByte == '1'){
        port = 10;
        }
      if(inByte == '2'){
        port = 11;
        }
      }
    if(('0'<= inByte) && (inByte <= '9') && (state == 1)){
      buff += inByte;
      }
    if((inByte == '\n') && (state == 1)){
      brightness = buff.toInt();
      Serial.println(brightness);
      analogWrite(port,int(brightness*2.54));
      }  
  }
}
