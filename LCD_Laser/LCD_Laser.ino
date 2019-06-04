/*

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 * This code uses the Arduino LCD Hello World example for reference.
 
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Charging laser..");
  pinMode(LED_BUILTIN,OUTPUT);//this is the led on the arduino
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  lcd.print("Charging laser..");
  /*
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  */
  for(int i = 0; i<12; i++){
    lcd.setCursor(i,1);//i in the second row
    lcd.write("#");
    if(i != 0 && i%2 == 0){
      digitalWrite(7+(i/2),HIGH);
    }
    delay(500);
  }
  for(int i = 0; i<10; i++){
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN,LOW);
    delay(100);
  }
  digitalWrite(LED_BUILTIN,LOW);
  lcd.noDisplay();
  lcd.clear();
  for(int i = 0; i<=5; i++){
    digitalWrite(8+i,LOW);
  }
  delay(5000);
  lcd.display();
}
