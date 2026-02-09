#include <Servo.h>
#include <I2C_RTC.h>
#include <DHT11.h>
#include <DHT.h>
#include <DHT_U.h>

#define PIN_DHT 3
#define PIN_LED 4
#define PIN_MOTOR 5
#define PIN_LIGHT A0

Servo motor;
DHT dht(PIN_DHT, DHT11);
void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_LIGHT, INPUT);
  pinMode(PIN_MOTOR, OUTPUT);
  motor.attach(PIN_MOTOR);
  dht.begin ();
  Serial.begin(9600);
}


void loop() {
  if (Serial.available() > 0) {
    String commande = Serial.readStringUntil('\n'); 
    commande.trim();
    if (commande.length() > 0) 
      traitement(commande);
  }
}

void traitement(String commande) {
  if (commande == "light_on") {
    digitalWrite(PIN_LED, HIGH);
  } 
  else if (commande == "light_off") {
    digitalWrite(PIN_LED, LOW);
  } 
  else if (commande == "get_temperature") {
    Serial.println("temp:"+String(dht.readTemperature()));
  } 
  else if (commande == "get_humidity") { 
    Serial.println("hum:"+String(dht.readHumidity()));
  } 
  else if (commande == "get_light") {
    sendLight();
  } 
  else if (commande == "open")
    openDoor();
    
  else if (commande == "close")
    closeDoor();
}


void sendLight(){
  float light  = map(analogRead(PIN_LIGHT),0,1023,0,5);
  light = 1000/((5/light)-1);
  light  = pow(500000/light, 1.25);
  Serial.println("light:"+String(light));     
}

void openDoor(){
  for(int i = 0; i<=180;i++){
    motor.write(i);
    delay(20);
  }
}

void closeDoor(){
  for(int i = 180; i>=0;i--){
    motor.write(i);
    delay(20);
  }
}
