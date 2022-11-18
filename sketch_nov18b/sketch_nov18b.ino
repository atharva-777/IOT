#include<DHT.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ThingSpeak.h>

#define DHTPIN D5
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

const char *ssid = "Y53s";
const char *password = "12345678";

WiFiClient client;

unsigned long myChannelNumber = 1016656;
const char *myWriteAPIKey = "XFG3D1F5D4YGXXXZ";

uint8_t temperature,humidity;

void setup(){
  Serial.begin(115200);
  dht.begin();
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    }  
    Serial.println(".");
    Serial.println("WiFi connected");
    Serial.println(WiFi.localIP());
    ThingSpeak.begin(client);
}

void loop(){
    static boolean data_state = false;
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();
    Serial.print("Temperature value is : ");
    Serial.print(temperature);
    Serial.println("C");
    Serial.print("Humidity value is : ");
    Serial.print(humidity);
    Serial.println("%");

    if(data_state){
        ThingSpeak.writeField(myChannelNumber,1,temperature,myWriteAPIKey);
        data_state = false;
      }
      else{
          ThingSpeak.writeField(myChannelNumber,2,humidity,myWriteAPIKey);
          data_state = true;
        }
    delay(30000);
  }
