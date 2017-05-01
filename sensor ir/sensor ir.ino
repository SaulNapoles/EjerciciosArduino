const int sensorPin = 9;
int ledPin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
int value = 0;
value = digitalRead(sensorPin);

if (value == LOW){
  Serial.println("Detectando algo"); 
  digitalWrite(ledPin,HIGH);
  
}else {
  digitalWrite(ledPin, LOW);
  }
delay(250);

}
