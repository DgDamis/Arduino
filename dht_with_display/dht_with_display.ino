int LED[] = {2,3,4,5,6,7,8};
#define prep_led = 9;
#include "DHT.h"
#define button 11
#define DHTPIN 12    
int lenght = 7;
#define DHTTYPE DHT11   
int prepnuti = 0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  for(int i = 2;i<9;i++) {
    pinMode(LED[i],OUTPUT);
    digitalWrite(LED[i], LOW); 
  }
  dht.begin();
}

void loop() {
  delay(2000);

    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);
    int intT = (int)t;
    String stringT = String(intT,BIN);
    int intH = (int)h;
    String stringH = String(intH,BIN);
    
    if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

    float hif = dht.computeHeatIndex(f, h);
    float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(stringH);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(stringT);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.print(" *F ");
  
  
  Serial.print("Delka: ");
  Serial.println(lenght);
  switch(prepnuti) {
   case 0:  
            lenght = stringT.length();
            for(int i = 1; i < length ; i++){
            if(stringT[lenght-i] == '1'  ) {
              digitalWrite(LED[i-1], HIGH);
              }
            else {
               digitalWrite(LED[i-1], LOW);
              }
            }
            break;
  case 1:   
            lenght = stringH.length();
            for(int i = 1; i < length ; i++){
            if(stringH[lenght-i] == '1'  ) {
              digitalWrite(LED[i-1], HIGH);
              }
            else {
               digitalWrite(LED[i-1], LOW);
              }
            }
            break;
  }

  if(digitalRead(button) == HIGH) {
     if(prepnuti == 0) {
        prepnuti = 1;
        digitalWrite(prep_led, HIGH);
        delay(200);
     }
     else {prepnuti = 0;
        digitalWrite(prep_led, LOW);
        delay(200);
     }
    }
      
    }

