#include<Servo.h>

#define trigPin 9
#define echoPin 8

Servo servo;
int sound = 250;

void setup(){
    Serial.begin(9600);
    pinMode(trigPin,OUTPUT);
    pinMode(echoPin,INPUT);
    servo.attach(6);
  }

 void loop(){
    long duration,distance;
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);
    distance = (duration/2)/29.1;

    if(distance<40){
        Serial.print(distance);
        Serial.println(" cm");
        servo.write(90);
      }
      else{
          Serial.println("The distance is greater");
        }
        delay(500);
        servo.write(-90);
  }
