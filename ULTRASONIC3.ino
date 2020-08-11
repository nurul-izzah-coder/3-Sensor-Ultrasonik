#include <NewPing.h>
#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#define TRIGGER_PIN1 12
#define ECHO_PIN1 13
#define TRIGGER_PIN2 10
#define ECHO_PIN2 11
#define TRIGGER_PIN3 8
#define ECHO_PIN3 9
#define MAX_DISTANCE 200
// NewPing setup of pins and maximum distance.
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE); 
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); 
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE); 
void setup() {
   Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("ULTRASONIC");
  delay(500);
    lcd.clear();
}
void loop() {
   delay(50);
   unsigned int uS1 = sonar1.ping_median();
   unsigned int uS2 = sonar2.ping_median();
   unsigned int uS3 = sonar3.ping_median();
   lcd.setCursor(0, 0);
   lcd.print("P1=");
   lcd.print(uS1);
   lcd.print("cm ");

   lcd.setCursor(7, 0);
   lcd.print(" P2=");
   lcd.print(uS2);
   lcd.print("cm");

   lcd.setCursor(0, 1);
   lcd.print("P3=");
   lcd.print(uS3);
   lcd.print("cm ");

   Serial.print(" P1 = ");
   Serial.print(uS1);
   Serial.print(" cm "); 

   Serial.print(" P2 = ");
   Serial.print(uS2);
   Serial.print(" cm "); 

   Serial.print(" P3 = ");
   Serial.print(uS3);
   Serial.println(" cm "); 
   delay(500);
}
