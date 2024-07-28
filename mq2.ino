#define BLYNK_TEMPLATE_ID "TMPL3b_bv72q1"
#define BLYNK_TEMPLATE_NAME "HAZARD DETECTION"
#define BLYNK_AUTH_TOKEN "40cCrlZTLOPbWprc1seSL7-rnHQxLcHt"
#define BLYNK_PRINT Serial  

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "iPhone8008";
char pass[] = "7006960196";

int buzzerPin = D3;  // Define buzzer pin
int smokeSensorPin = A0;  // Define smoke sensor pin

int sensorThreshold = 600;  // Threshold value for smoke detection

void setup() {
  pinMode(buzzerPin, OUTPUT);  // Initialize buzzer pin as output
  pinMode(smokeSensorPin, INPUT);  // Initialize smoke sensor pin as input
  Serial.begin(9600);  // Start serial communication
  Blynk.begin(auth, ssid, pass);  // Initialize Blynk
}

void loop() {
  Blynk.run();  // Run Blynk tasks

  int analogSensor = analogRead(smokeSensorPin);  // Read analog value from smoke sensor

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);

  if (analogSensor > sensorThreshold) {
    tone(buzzerPin, 1000, 200);  // Generate tone on buzzer pin
    Serial.println("GAS DETECTED");
    Blynk.logEvent("alert__fire_detected");  // Log event in Blynk
  } else {
    noTone(buzzerPin);  // Turn off buzzer
  }
  delay(100);
}
