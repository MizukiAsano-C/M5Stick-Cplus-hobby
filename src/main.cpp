#include <M5StickCPlus.h>

#define MAIN_BUTTON 37

void setup()
{
  M5.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.setRotation(3);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("Hello world");
  Serial.begin(115200);
  pinMode(MAIN_BUTTON, INPUT);
}

void loop()
{
  static bool button_pressed = true;
  static bool printed = false;
  static int count = 0;

  bool now_button;

  now_button = !digitalRead(MAIN_BUTTON);

  if ((button_pressed == false) && (now_button == true))
  {
    button_pressed = true;
  }
  else if (now_button == false)
  {
    button_pressed = false;
    printed = false;
  }

  M5.update();
  if (button_pressed && !printed)
  {
    M5.Lcd.println("Hello world");
    count++;
    printed = true;
  }

  if (count > 6)
  {
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);
    count = 0;
  }
}