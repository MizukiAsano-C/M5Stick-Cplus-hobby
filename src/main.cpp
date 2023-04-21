#include <M5StickCPlus.h>

#define MAIN_BUTTON 37

void setup()
{
  M5.begin();
  M5.Lcd.print("Hello world");
  Serial.begin(115200);
  pinMode(MAIN_BUTTON, INPUT);
}

void loop()
{
  M5.update();
  if (digitalRead(MAIN_BUTTON))
  {
    M5.Lcd.fillScreen(TFT_BLACK);
    M5.Lcd.print("Hello world");
  }
  else
  {
    M5.Lcd.fillScreen(BLUE);
  }
  delay(500);
}