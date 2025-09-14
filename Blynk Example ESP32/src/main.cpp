//Include the library files
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Arduino.h>
#include <DHT_Async.h>

#define BLYNK_TEMPLATE_ID "TMPL2o8yilbYX"
#define BLYNK_TEMPLATE_NAME "Hydronano"
#define BLYNK_AUTH_TOKEN "sD09Q81Uq-NB64gFHMgQkDuWeLaUk-BR"

/* ---- PROCEDURE -----

1. Find authurization token, SSID, and password for wifi WAN connection to Blynk servers
2. Set up pins as output/input
3. Run Blynk.begin in setup()
4. Run Blynk.run() in loop() to maintain connection & data transfer
5. Read for pin and send data from ESP to server
6. Blynk can toggle GPIO on device without device code, just set up datastream output from server


*/
// Enter your Auth token
char auth[] = BLYNK_AUTH_TOKEN;

//Enter your WIFI SSID and password
char ssid[] = "SpectrumSetup-5D";
char password[] = "ancientpoodle638";


void setup(){
  Serial.begin(115200);
  /*WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  */
  Blynk.begin(auth, ssid, password);
  delay(100);
}

void loop(){
  /*Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI()); delay(2000);*/
  Blynk.run();
  
}
