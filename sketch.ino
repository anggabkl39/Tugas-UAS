#include <LiquidCrystal_I2C.h>
#define ECHO_PIN 2
#define TRIG_PIN 3
#define buzzer 4
#define ledmerah 13
#define ledkuning 12
#define ledhijau 11

LiquidCrystal_I2C lcd(0x27,20,4);
void setup() {
  pinMode(ledmerah, OUTPUT);
  pinMode(ledkuning, OUTPUT);
  pinMode(ledhijau, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  digitalWrite(ledmerah, HIGH);
  digitalWrite(ledkuning, HIGH);
  digitalWrite(ledhijau, HIGH);
  tone(4,300,500);
  lcd.setCursor(0,0);
  lcd.print("Alat Pengukur");
  lcd.setCursor(0,1);
  lcd.print("Ketinggian Air");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Angga Gustianto");
  lcd.setCursor(0,1);
  lcd.print("NPM : 21010039");
  delay(3000);
  digitalWrite(ledmerah, LOW);
  digitalWrite(ledkuning, LOW);
  digitalWrite(ledhijau, LOW);
  digitalWrite(buzzer, LOW);
  lcd.clear();
}

float kedalaman(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int durasi = pulseIn(ECHO_PIN, HIGH);
  return 400-durasi*0.034/2;
}

void loop() {
  float depth = kedalaman();
if(depth > 370)
  {
    digitalWrite(ledmerah, HIGH);
    digitalWrite(ledkuning, LOW);
    digitalWrite(ledhijau, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Depth :");
    lcd.setCursor(7,0);
    lcd.print(depth);
    lcd.setCursor(14,0);
    lcd.print("cm");
    lcd.setCursor(0,1);
    lcd.print("Status :");
    lcd.setCursor(9,1);
    lcd.print("Bahaya");
    tone(4,800,1000);
    delay(1000);
    lcd.clear();
    delay(100);
  }
  else{
    if(depth >= 320 && depth < 370)
  {
    digitalWrite(ledmerah, LOW);
    digitalWrite(ledmerah, HIGH);
    digitalWrite(ledhijau, LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Depth :");
    lcd.setCursor(7,0);
    lcd.print(depth);
    lcd.setCursor(14,0);
    lcd.print("cm");
    lcd.setCursor(0,1);
    lcd.print("Status :");
    lcd.setCursor(9,1);
    lcd.print("Siaga");
  
    delay(1000);
    lcd.clear();
    delay(100);
  }
  else{
    digitalWrite(ledmerah, LOW);
    digitalWrite(ledkuning, LOW);
    digitalWrite(ledhijau, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Depth :");
    lcd.setCursor(7,0);
    lcd.print(depth);
    lcd.setCursor(14,0);
    lcd.print("cm");
    lcd.setCursor(0,1);
    lcd.print("Status :");
    lcd.setCursor(9,1);
    lcd.print("Aman");
    
    delay(1000);
    lcd.clear();
    delay(100);
  }
  }


}
