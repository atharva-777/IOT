#include <ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial

int sensorpin = A0;
int sensorvalue = 0;
int outputvalue = 0;


char auth[] = "";

char ssid[] = "Y53s";
char pass[] = "12345678";

void setup(){

    Serial.begin(9600);
    Blynk.begin(auth,ssid,pass);
  }

  void loop(){
      sensorvalue = analogRead(sensorpin);
      outputvalue = map(sensorvalue,0,1023,0,100);
      delay(1000);
      if(outputvalue>74){
          Serial.println("water your plant");
          Serial.println(outputvalue);
          Blynk.notify("water your plant");
          delay(1000);
        }else if(outputvalue<45){
            Serial.println("soil is wet enough to water");
            Serial.print(outputvalue);
            Blynk.notify("soil is wet enough to water");
            delay(1000);
          }
          Blynk.run();
    }
