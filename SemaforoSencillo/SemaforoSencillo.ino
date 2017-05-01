int rojo = 7;
int amarillo = 4;
int verde = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(rojo, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(verde, HIGH);
  delay(2000);
  digitalWrite(verde, LOW);
  delay(500);

  digitalWrite(amarillo, HIGH);
  delay(2000);
  digitalWrite(amarillo, LOW);
  delay(500);

  digitalWrite(rojo, HIGH);
  delay(2000);
  digitalWrite(rojo, LOW);
  delay(500);
}
