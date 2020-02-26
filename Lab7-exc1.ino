#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1
#define SW1 10
#define SW2 11
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); 

void setup() {
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //initialize I2C addr 0x3c
  display.clearDisplay(); 
}

void loop() {
  int b1 = digitalRead(SW1);
  int b2 = digitalRead(SW2);
  if(b1 == 1 && b2 == 1){
    display.clearDisplay();
    display.drawCircle(20, 10, 8, WHITE);
    display.drawCircle(20, 30, 8, WHITE);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,45);
    display.println("SW1 and SW2 are not");
    display.println("activate");
    display.display();
  }
  else if(b1 == 1 && b2 == 0){
    display.clearDisplay();
    display.drawCircle(20, 10, 8, WHITE);
    display.fillCircle(20, 30, 8, WHITE);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,45);
    display.println("SW2 is activate but");
    display.println("SW1 is not activate");
    display.display();
  }
  else if(b1 == 0 && b2 == 1){
    display.clearDisplay();
    display.fillCircle(20, 10, 8, WHITE);
    display.drawCircle(20, 30, 8, WHITE);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,45);
    display.println("SW1 is activate but");
    display.println("SW2 is not activate");
    display.display();
  }
  else{
    display.clearDisplay();
    display.fillCircle(20, 10, 8, WHITE);
    display.fillCircle(20, 30, 8, WHITE);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,45);
    display.println("SW2 and SW1 are activate");
    display.display();
  }
  Serial.print(b1);
  Serial.print(" ");
  Serial.println(b2);
}
