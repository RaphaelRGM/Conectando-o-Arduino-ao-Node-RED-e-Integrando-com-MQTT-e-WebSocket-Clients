#include <ArduinoJson.h>

const int pino_potenciometro = A0;
int valor_potenciometro;

void setup() {
  Serial.begin(9600);
  Serial.println("======================================");
  Serial.println("Bem-vindo ao <<MonteCarloDigital>>");
  Serial.println("Monitoramento do Potenciômetro");
  Serial.println("======================================");
}

void loop() {
  delay(1000);
  
  valor_potenciometro = analogRead(pino_potenciometro);

  StaticJsonDocument<200> doc;
  doc["sensor"] = "Potenciometro";
  doc["valor"] = valor_potenciometro;

  String json;
  serializeJson(doc, json);
  Serial.println(json);
}
