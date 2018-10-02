#include "LiquidCrystal.h"

LiquidCrystal lcd(3,4,6,7,8,9);
int timerStart=11;
int counter=timerStart;
int score=0;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Let's go!");
  delay(3000);
}


void timerSetup(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Let's go!");
  delay(3000);
  }

int timer(){ 
counter--;
return counter;
}


void printTimeScore(int t, int s){
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Time:");
  lcd.setCursor(0,1);
  lcd.print(t);

  lcd.setCursor(8,0);
  lcd.print("Score:");
  lcd.setCursor(8,1);
  lcd.print(s);
  }

  void printAndRestart(int t, int s){
    if(t==-1){
      lcd.clear();
      lcd.print("Time's up!");
      counter=timerStart;
      delay(3000);
      timerSetup();
    }else if(t>=0){
      printTimeScore(t,s);
    }
  }


void loop() {
  // put your main code here, to run repeatedly:
  int t=timer();
  printAndRestart(t,score);
  delay(1000);

}
