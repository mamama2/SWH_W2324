#include <ThingSpeak.h>

/*
   Sketching mit Hardware
  DMP - WS 23_24
  - NodeMCU ESP8266 Temperature/Humidity IoT Demo (Thingspeak)
This code send to  Thingspeak DHT22 data each 20 seconds -using wifi
Martinez
*/

#include <DHT.h> //cargamos la librera DHT
#define DHTPIN 1 //Seleccionamos el pin en el que se conectar el sensor
#define DHTTYPE DHT11 //Se selecciona el DHT22(hay otros DHT)
DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que ser usada por Arduino para comunicarse con el sensor
#include <ESP8266WiFi.h>

unsigned long myChannelNumber = 1580381;
const char * myWriteAPIKey = "KJGBEAOA8ACDO30J";

const char* ssid = "Vodafone-75D4";
const char* password = "rb7d2kxXn2s7zyMp";

 WiFiClient  client;
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
   dht.begin(); //Se inicia el sensor

 

 
  
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");  
  
  // Start the server
 // server.begin();
  //Serial.println("Server started");
   
 

  // Print the IP address
  Serial.println(WiFi.localIP());

ThingSpeak.begin(client);
   
}

void loop() {

float h = dht.readHumidity(); //Se lee la humedad
  float t = dht.readTemperature(); //Se lee la temperatura
  //Se imprimen las variables
  Serial.println("Humedad: "); 
  Serial.println(h);
  Serial.println("Temperatura: ");
  Serial.println(t);
  delay(2000); //Se espera 2 segundos para seguir leyendo //datos
 

ThingSpeak.writeField(myChannelNumber, 1, h, myWriteAPIKey);
  delay(2000); 
  

ThingSpeak.writeField(myChannelNumber, 2, t, myWriteAPIKey);
  delay(10000); 
  
  


 
   }
 
    
  
  
 
