//Include the library files
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Arduino.h>
#include <DHT_Async.h>

#define BLYNK_TEMPLATE_ID "TMPL2edoi4b7r"
#define BLYNK_TEMPLATE_NAME "Blink ESP32"
#define BLYNK_AUTH_TOKEN "CCXk7-6p7EA2FgUYEqy2TgVMHouSRAlP"

// Enter your Auth token
char auth[] = "CCXk7-6p7EA2FgUYEqy2TgVMHouSRAlP";

//Enter your WIFI SSID and password
char ssid[] = "SpectrumSetup-5D";
char pass[] = "ancientpoodle638";
unsigned long previousMillis = 0;
unsigned long currentMillis;
int interval = 1000;
int state;

DHT_Async dht_sensor = DHT_Async(33, 3);

static bool measure_environment(float*, float*);

void setup(){
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  
}

void loop(){
  float temperature;
  float humidity;

  Blynk.run();
  currentMillis = millis();
  if((currentMillis -  previousMillis) > interval) {

  if (measure_environment(&temperature, &humidity)) {
          Serial.print("T = ");
          Serial.print(temperature, 1);
          Serial.print(" deg. C, H = ");
          Serial.print(humidity, 1);
          Serial.println("%");
      }
    previousMillis = currentMillis;
  }
}

static bool measure_environment(float *temperature, float *humidity) {
    static unsigned long measurement_timestamp = millis();

    /* Measure once every four seconds. */
    if (millis() - measurement_timestamp > 4000ul) {
        if (dht_sensor.measure(temperature, humidity)) {
            measurement_timestamp = millis();
            return (true);
        }
    }

    return (false);
}
