#define BLYNK_TEMPLATE_ID "TMPL3b_bv72q1"
#define BLYNK_TEMPLATE_NAME "HAZARD DETECTION"
#define BLYNK_AUTH_TOKEN "40cCrlZTLOPbWprc1seSL7-rnHQxLcHt"
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
  Blynk.logEvent("alert__fire_detected");  
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