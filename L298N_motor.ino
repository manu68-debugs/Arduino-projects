int in1 = 6;
int in2 = 7;
int ena = 5;

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);

}

void loop() {
  analogWrite(ena, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(2000);
  digitalWrite(in1,LOW);
  digitalWrite(in2, LOW);
  delay(4000);
  analogWrite(ena, 100);
  digitalWrite(in1,HIGH);
  digitalWrite(in2, LOW);
  delay(2000);
  digitalWrite(in1,LOW);
  digitalWrite(in2, LOW);
  delay(4000);
}
