#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 
ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);

void printDate(const RtcDateTime& dt){
  display.print(dt.Year(), DEC);
  display.print('/');
  display.print(dt.Month(), DEC);
  display.print('/');
  display.print(dt.Day(), DEC);
  display.print(' ');
  display.println();
}

void printTime(const RtcDateTime& dt){
  display.print(dt.Hour(), DEC);
  display.print(':');
  display.print(dt.Minute(), DEC);
  display.print(':');
  display.print(dt.Second(), DEC);
  display.println();
}

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay(); 
  Rtc.Begin();
  RtcDateTime setting_time(2020,2,26,10,21,0);
  // year, month, dayOfMonth, hour, minute, second

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  printDate(setting_time);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
  printTime(setting_time);
  
  Rtc.SetDateTime(setting_time);
}

void loop() {
  RtcDateTime now = Rtc.GetDateTime();

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10,20);
  printDate(now);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(40,40);
  printTime(now);
 
  display.display();
  delay(500);
}
