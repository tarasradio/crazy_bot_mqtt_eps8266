#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <PubSubClient.h>

//SSID and Password of your WiFi router
//const char* ssid = "KVANTORIUM34IT349";
//const char* password = "it349Impossible";

const char* ssid = "TARASRADIO";
const char* password = "12345678";

//Enter your mqtt server configurations
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* commandsTopic = "crazyBot666/commands";
const char* debugTopic = "crazyBot666/debug";
 
WiFiClient espClient;
PubSubClient client(espClient);

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");

  String message;
  for (int i = 0; i < length; i++) {
    message = message + (char)payload[i];  //Conver *byte to String
  }

   Serial.print(message);
  if(message == "#f") {
    Serial1.write('f');
  } 
  if(message == "#b") {
    Serial1.write('b');
  }
  if(message == "#l") {
    Serial1.write('l');
  }
  if(message == "#r") {
    Serial1.write('r');
  }
  if(message == "#s") {
    Serial1.write('s');
  }
 
  Serial.println();
  Serial.println("-----------------------");  
}

void connectToNetwork() {
  WiFi.begin(ssid, password);
  Serial.println("");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void connectToMqtt() {
  client.setServer(mqttServer, mqttPort);
  client.setCallback(mqttCallback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP8266")) {
      Serial.println("connected to MQTT");
    } else {
      Serial.print("failed with state ");
      Serial.println(client.state());  //If you get state 5: mismatch in configuration
      delay(2000);
    }
  }
 
  client.publish(debugTopic, "Bot is ready!");
  client.subscribe(commandsTopic);
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  connectToNetwork();
  connectToMqtt();
}

void loop() {
  client.loop();
}