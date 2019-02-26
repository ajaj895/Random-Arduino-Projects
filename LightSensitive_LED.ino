
//use PWM pins for pulse with modulation, for finite controls of the voltages to make the transition smooth
//IMPORTANT: use a 220 ohm resistor for the leds so you don't burn them out
//TESTED WITH: ky-009 SMD RGB LED module, and ky-016 RGB LED module, and both at the same time.

//pin locations corisponding to the pins on the arduino
// - to ground on the led(s)
int sensorPin = A0;//pin the light sensor is connected to (analog)
int redpin = 9; //the pin for the R (red) RGB
int greenpin = 10; //the pin for the G (green) RGB
int bluepin = 11; //the pin for the B (blue) RGB

//values for the color
int red = 0;
int green = 0;
int blue = 0;
//light from the ky-018 module
int light = analogRead(sensorPin)/4;


void setup() {
  // put your setup code here, to run once:
  pinMode (redpin, OUTPUT);
  pinMode (greenpin, OUTPUT);
  pinMode (bluepin, OUTPUT);
  Serial.begin(9600);//for testing purposes
  if(light > 250){
    light = 250;
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  while (red < 255-light){
    if(blue == 0){
      red++;
      analogWrite (redpin, red);
      light = analogRead(sensorPin)/4;
      delay(15);//15 is a good slow speed
      Serial.println(light);
      if(light > 250){
        light = 250;
      }
    }
    else{
      red++;
      blue--;
      analogWrite (redpin, red);
      analogWrite (bluepin, blue);
      light = analogRead(sensorPin)/4;
      delay(15);
      Serial.println(light);
      if(light > 250){
        light = 250;
      }
    }
  }
  blue = 0;
  while (green < 255-light){
    green++;
    red--;
    analogWrite (greenpin, green);
    analogWrite (redpin, red);
    light = analogRead(sensorPin)/4;
    delay(15);
    Serial.println(light);
    if(light > 250){
       light = 250;
    }
  }
  red = 0;
  while (blue < 255-light){
    blue++;
    green--;
    analogWrite (bluepin, blue);
    analogWrite (greenpin, green);
    light = analogRead(sensorPin)/4;
    delay(15);
    Serial.println(light);
    if(light > 250){
       light = 250;
    }
  }
  
}//low light equals lower light level and faster transition
  
  
