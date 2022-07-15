#include <ESP8266WiFi.h>

#define pushPin D3 

const char* ssid = "RAKESH";
const char* password = "Rakesh@2001";


const char* host = "maker.ifttt.com";

void setup() 
{
    Serial.begin(115200);
    Serial.println("Email from Node Mcu");
    delay(100);
    delay(1000);
    pinMode(pushPin , INPUT);

   connectWiFi(); 


}

void loop() 
{   
    
      while((!(WiFi.status() == WL_CONNECTED)))
    {
      connectWiFi();
    }               
      WiFiClient client; 
      const int httpPort = 80;  
      if (!client.connect(host, httpPort)) 
      {  
         Serial.println("connection failed");  
         return;
      } 
     
      
      
     
         
         if (digitalRead(pushPin) == HIGH)
        {    
            String url = "/trigger/ard2/json/with/key/iEOVR3Uqmyn7YRWXrBqi3HPhOs3o-VBaUISXpAFipBq"; 
            Serial.print("Requesting URL: ");
            Serial.println(url);                 
            client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");    
         }                     
          else
          {
            Serial.println("Correct character not pressed.Try again");            
          }
               
       delay(1000);  
    while((!(WiFi.status() == WL_CONNECTED)))
    {
      connectWiFi();
    }              
}

void connectWiFi()
{ 
  int i=0;
  Serial.println("Connecting to WIFI");
  WiFi.begin(ssid, password);
  while((!(WiFi.status() == WL_CONNECTED)))
  {
    Serial.println(" - "); 
    i++;
    delay(300);
    if( i>10 )    
    { 
     connectWiFi();
    }
   }  
   Serial.println("");
   Serial.println("WiFi connected");
}
