//Relay tester on an arduino nano.
//Relay on digital pin8

int relay = 8;
void setup() {
  // put your setup code here, to run once:
  pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay,HIGH);//relay on

  delay(2000);//wait two seconds

  digitalWrite(relay,LOW);//relay off

  delay(2000);//wait two seconds

}
