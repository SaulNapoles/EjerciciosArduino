/*
 sensor sonico HC-SR04 conexiones:
  VCC al arduino 5v 
  GND al arduino GND
  Echo al Arduino pin 6 
  Trig al Arduino pin 7
  */
 
#define Pecho 6
#define Ptrig 7
long duracion, distancia;   
long distanciaPermitida = 50; //centimetros 

void setup() {                
  Serial.begin (9600);       
  pinMode(Pecho, INPUT);     // define el pin 6 como entrada del pin echo
  pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida del triger
  pinMode(13, 1);            // led 
  }
  
void loop() {
  
  generarPulsaciones();
  
  calcularDistacia();
}

void generarPulsaciones(){
  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
}

void calcularDistacia(){
    
  duracion = pulseIn(Pecho, HIGH);  //recibe o lee las pulsaciones
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros par que sea mas precisa
  
  if (distancia >= 500 || distancia <= 0){  // si la distancia de las pulsaciones es mayor a 500cm (5 metros) o menor a 0cm 
    Serial.println("------fuera del rango-------");    
  }
  else {
    Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
    Serial.println("cm");              
    digitalWrite(13, 0);               // se apaga el led (pin 13)
  }
  
  encenderLed(distancia);                               
}

void encenderLed(long distancia){
  
  if (distancia <= distanciaPermitida && distancia >= 1){
    digitalWrite(13, 1);                     // se enciende el pin 13 si la distancia es menor a la distancia permitida
    Serial.print("se detecto algo a ");
    Serial.print(distancia);
    Serial.println(" cm de distancia ");         // envia la palabra Alarma por el puerto serial
  }
  delay(400);  // espera 400ms para que se logre ver la distancia en la consola
}

