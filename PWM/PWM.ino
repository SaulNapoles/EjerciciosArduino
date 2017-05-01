int led[5] = {3,5,6,9,10};
int i, j;
int repeat = 10;
void setup() {
  // put your setup code here, to run once:
  for(i=0; i<5; i++) 
  pinMode(led[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(j=0; j<repeat; j++){
    for(i=0; i<256; i++){
      analogWrite(led[0],i);
    }
    for(i=50; i>-1; i--){
      analogWrite(led[0],i);
      analogWrite(led[1],255-i);
    }
    for(i=0; i<52; i++){
      analogWrite(led[1],255-i);
      analogWrite(led[2],i);
    }
    for(i=50; i>-1; i--){
      analogWrite(led[2],i);
    }
    
    for(i=0; i<52; i++){
      analogWrite(led[2],i);
    }
    for(i=50; i>-1; i--){
      analogWrite(led[2],i);
      analogWrite(led[1],255-i);
    }
    for(i=0; i<52; i++){
      analogWrite(led[1],255-i);
      analogWrite(led[0],i);
    }
    for(i=50; i>-1; i--){
      analogWrite(led[0],i);
    }
    
  }
  
  for(i=0; i<repeat; i++){
    analogWrite(led[0],random(0,256));
    delay(random(0,501));
    analogWrite(led[1],random(0,256));
    delay(random(0,501));
    analogWrite(led[2],random(0,256));
    delay(random(0,501));
    analogWrite(led[3],random(0,256));
    delay(random(0,501));
    analogWrite(led[4],random(0,256));
    delay(random(0,501));
    
  }
}
