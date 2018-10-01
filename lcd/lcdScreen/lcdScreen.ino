#include "LiquidCrystal.h"

LiquidCrystal lcd(7,8,9,3,6,4);
int counter = 60;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);



}

void timer(){ 
  lcd.setCursor(0,0);
    lcd.print("Let's go!");
    delay(3000);
    lcd.clear();
    for(counter=60;counter>=0;counter--){
      lcd.print("Time:");
      lcd.setCursor(0,1);
      lcd.print(counter);
      delay(1000);
      lcd.clear();
      if (counter ==0){
    lcd.setCursor(0,1);
    lcd.print("Time's up!");
    delay(1000);
    lcd.clear();
    }
  }
}

void printScore(int score){
  lcd.setCursor(8,0);
  lcd.print("Score:");
  lcd.setCursor(8,1);
  lcd.print(score);
}


void loop() {
  // put your main code here, to run repeatedly:
  timer();

  delay(1000);

}
