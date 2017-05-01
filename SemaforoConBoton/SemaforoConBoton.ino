int redLed1=12;
int yellowLed=11;
int greenLed1=10;
int redLed2=7;
int greenLed2=6;
int buttonPin=2;
int state=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed1, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed1, OUTPUT);
  pinMode(redLed2, OUTPUT);
  pinMode(greenLed2, OUTPUT);
   pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(greenLed1, HIGH);
 digitalWrite(redLed2, HIGH);
 
 state=digitalRead(buttonPin);
 
 if(state==HIGH){
 digitalWrite(greenLed1, LOW);
 digitalWrite(yellowLed, HIGH);
 delay(1000);
 
 digitalWrite(yellowLed, LOW);
 digitalWrite(redLed1, HIGH);
 digitalWrite(redLed2, LOW);
 digitalWrite(greenLed2, HIGH);
 delay(200);
 
 digitalWrite(redLed1, LOW);
 digitalWrite(greenLed2, LOW);
 }

}
