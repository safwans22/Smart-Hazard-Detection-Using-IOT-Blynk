#define BLYNK_TEMPLATE_ID "TMPL3DR7p2bJo"
#define BLYNK_TEMPLATE_NAME "HAZARD DETECTION SYSTEM"
#define BLYNK_AUTH_TOKEN "li3Uj2fX96kiMBvajPCJWneSwqkitKF5"
#define BLYNK_PRINT Serial  


 #include <ESP8266WiFi.h>  
 #include <BlynkSimpleEsp8266.h>  

 char ssid[] = "iPhone8008"; //Wifi name  
 char pass[] = "7006960196"; //Wifi Password  
 BlynkTimer timer; 
 int flag=0;  
 void notifyOnFire()  
 {  
  int isButtonPressed = digitalRead(D1);  
  if (isButtonPressed==1 && flag==0) {  
   Serial.println("Fire DETECTED");  
  Blynk.logEvent("Alert : Fire detected");  
   flag=1;  
  }  
  else if (isButtonPressed==0)  
  {  
   flag=0;  
  }  
 }  
 void setup()  
 {  
 Serial.begin(9600);  
 Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  
 pinMode(D1,INPUT_PULLUP);  
 timer.setInterval(1000L,notifyOnFire);   
 }  
 void loop()  
 {  
  Blynk.run();  
  timer.run();  
 }  