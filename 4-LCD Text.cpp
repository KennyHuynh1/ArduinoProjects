#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6 , 7); // object of syntax LiquidCrystal(rs, enable, d4, d5, d6, d7)

// custom creation of characters made of 5x8 pixels
// B stands for binary format and each digit are the actual pixels on the LCD with 1 being on and 0 off
byte smile[8] = {
  B00000,
  B00000,
  B01010,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte rectangle[8] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
};

byte heart[8] = {
  B00000,
  B00000,
  B00000,
  B11011,
  B10101,
  B01010,
  B00100,
  B00000,
};

void setup() {
  lcd.begin(16, 2); // dimensions of lcd

  // can support up to 8 custom characters (0-7)
  lcd.createChar(5, smile);
  lcd.createChar(6, rectangle);
  lcd.createChar(7, heart);

  lcd.clear();

  lcd.print("Hello World!");
  delay(2000);

  lcd.setCursor(0, 1); // sets the cursor to 0th column and 1st row with the origin at top left
  lcd.print("Welcome!");
  delay(2000);

  lcd.clear(); // clears screen and set cursor to (0, 0)

  lcd.print("01/07/20");
  for(int i = 0 ; i < 16 ; i++){
    lcd.scrollDisplayRight(); // scrolls from left to right until the first character is not seen
    delay(800);
  }
  lcd.clear();
}

void loop() {
  lcd.blink();
  delay(2000);

  // blinks and prints a character as if someone was typing it
  lcd.print("G");
  lcd.blink();
  delay(1000);
  lcd.print("o");
  lcd.blink();
  delay(1000);
  lcd.print("o");
  lcd.blink();
  delay(1000);
  lcd.print("d");
  lcd.blink();
  delay(1000);
  lcd.print("b");
  lcd.blink();
  delay(1000);
  lcd.print("y");
  lcd.blink();
  delay(1000);
  lcd.print("e");
  lcd.blink();
  delay(1000);
  lcd.print(" ");
  lcd.blink();
  delay(1000);
  lcd.write(5);
  lcd.blink();
  delay(1000);
  lcd.write(6);
  lcd.blink();
  delay(1000);
  lcd.write(7);
  lcd.blink();
  delay(1000);

  delay(3000);

  lcd.clear();
}