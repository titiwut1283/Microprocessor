#include <ThreeWire.h>  
#include <RtcDS1302.h>
ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  Serial.begin(57600);
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,19,9,31,10);
  // year, month, dayOfMonth, hour, minute, second

  Rtc.SetDateTime(setting_time);
  pinMode(13, OUTPUT);
  }
  
void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  if(now.Second()%2 == 1)
    digitalWrite(13, HIGH);
  if(now.Second()%2 == 0)
    digitalWrite(13, LOW);
  }
