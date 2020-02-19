#include <ThreeWire.h>  
#include <RtcDS1302.h>
ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

uint32_t previous_time;
/*
void printDateTime(const RtcDateTime& dt){
  Serial.print(dt.Year(), DEC);
  Serial.print('/');
  Serial.print(dt.Month(), DEC);
  Serial.print('/');
  Serial.print(dt.Day(), DEC);
  Serial.print(' ');
  Serial.print(dt.Hour(), DEC);
  Serial.print(':');
  Serial.print(dt.Minute(), DEC);
  Serial.print(':');
  Serial.print(dt.Second(), DEC);
  Serial.println();
  Serial.print("Total Seconds since 1/1/2000 : ");
  Serial.print(dt.TotalSeconds());
  Serial.println();
  }
*/
void setup() {
  Serial.begin(57600);
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,19,0,0,0);
  // year, month, dayOfMonth, hour, minute, second
  
  //printDateTime(setting_time);
  
  Rtc.SetDateTime(setting_time);
  pinMode(13, OUTPUT);
  Serial.println("3");
  delay(1000);
  Serial.println("2");
  delay(1000);
  Serial.println("1");
  delay(1000);
  RtcDateTime now = Rtc.GetDateTime();
  previous_time = now.TotalSeconds();
  Serial.println("Start");
  }
  
void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  if((now.TotalSeconds()-previous_time) < 120){
    if(now.Second() % 2 == 1){
      digitalWrite(13, HIGH);
      //Serial.println(now.Second());
      }
    if(now.Second() %2  == 0){
      digitalWrite(13, LOW);
      //Serial.println(now.Second());
     }
    }
    else if((now.TotalSeconds()>previous_time) && (now.TotalSeconds() <=(previous_time)+120)){
      Serial.println("Stop");
      digitalWrite(13, LOW);
    }
    //delay(10);
  }
