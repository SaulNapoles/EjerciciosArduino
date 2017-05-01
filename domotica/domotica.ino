// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 3     // what digital pin we're connected to
const int ledAzul = 5; //Pin del led azul (movimiento)
const int ledRojo = 8; //Pin de led rojo (Alarma)
const int btnAzul = 7; //Pin del boton del led azul (movimiento);
const int btnRojo = 9; //Pin del boton del led Rojo (Alarma)
const int pinPot = 0;
int valorPot = 0;
int valorBtn; //Valor del boton que se utilizara en el if
int alarma = 10; //Pin de la alarma;
int salidaBoton = 0; //leer salida del boton
int activado = 0;

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(ledAzul, OUTPUT);         // Ponemos el pin del LED como salida
  pinMode(btnAzul, INPUT);          // Ponemos el pin del botón como entrada
  pinMode(pinPot, INPUT);
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {

    valorPot = analogRead(pinPot);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledAzul, LOW);
    
    if(valorPot == 0) { //si el potenciometro llega a 0
    //activar sensor movimiento
    Serial.println("MOVIMIENTO (NOCHE)");
    activarMovimiento();
    }
    
  

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.println(" *F\t");
  // Wait a few seconds between measurements.
  delay(500);
}

void activarMovimiento() {
    valorBtn=digitalRead(btnAzul);
   
    if  (valorBtn==LOW){
    digitalWrite(ledAzul,HIGH);
    Serial.println("SE DETECTO MOVIMIENTO");
    delay(2000);
    funcionarAlarma();
    }
    
    else { digitalWrite(ledAzul,LOW);
    
    Serial.println("no se detecta nada");
    }
    
    }

void funcionarAlarma() {
  for(int i = 0; i <= 50; i++) {

    Serial.println("HAY UN INTRUSO CHAVO");
    delay(100);
    
    salidaBoton = digitalRead(btnAzul);
    if(salidaBoton == HIGH){
      activado = 1;
    }
    else {
      activado = 0;
    }
    
    if(activado == 1){ //si se activa el boton la alarma se desactiva
      Serial.println("ALARMA DESACTIVADA");
      digitalWrite(ledAzul, HIGH);
      noSonar();
      break;
    }
    else if (activado == 0 && i >= 50) { //si no se activa el boton la alarma empieza a sonar
      Serial.println("ALARMA ACTIVADA WIU WIU WIUW");
      sonar();
      digitalWrite(ledRojo, HIGH);
      delay(2000);
    }

    //Serial.println("HAY UN INTRUSO CHAVO");
    //delay(100);
  }
}


void sonar() {
  tone(alarma, 20000, 2000);
}

void noSonar(){
  noTone(alarma);
  delay(100);
}
