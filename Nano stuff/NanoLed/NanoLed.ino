void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);//arduino nano built in LED
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(150);
  digitalWrite(13, LOW);
  delay(150);
}
