int i=0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  Serial.println("Start");
}

void loop() {
  if(i%2 == 0){
    digitalWrite(13, HIGH);
  }
  if(i%2 == 1){
    digitalWrite(13, LOW);
  }
  if(i==120){
    Serial.println("Stop");
  }
  Serial.println(i);
  i++;
  delay(1000);
}
