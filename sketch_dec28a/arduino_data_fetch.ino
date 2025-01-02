#include <DHT.h>

#define DHT_PIN 2
#define TRIG_PIN 3 
#define ECHO_PIN 4
#define MQ9_PIN A0

DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(MQ9_PIN, INPUT);
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  return pulseIn(ECHO_PIN, HIGH) * 0.034 / 2;
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  float dist = getDistance();
  float gas = analogRead(MQ9_PIN);

  Serial.print("\r");
  Serial.print(temp, 1);
  Serial.print(",");
  Serial.print(hum, 1);
  Serial.print(",");
  Serial.print(dist, 1);
  Serial.print(",");
  Serial.print(gas, 1);

  delay(500);
}