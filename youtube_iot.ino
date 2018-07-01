#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

// Set these to run example.
#define FIREBASE_HOST "e-adawd.firebaseio.com"
#define FIREBASE_AUTH "qULRQbnuzJ3--------LlKtpXic1UQ1FxHvM"
#define WIFI_SSID "kavin"
#define WIFI_PASSWORD "12345612"
String status;
void setup() {
Serial.begin(9600);
pinMode(4, OUTPUT);
// connect to wifi.
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
// get value
status = Firebase.getString("on");
if(status=="1"){
digitalWrite(4,HIGH);
Serial.println("LED ON");

}
else {
Serial.println("LED OFF");
digitalWrite(4,LOW);  
return;
}
}
