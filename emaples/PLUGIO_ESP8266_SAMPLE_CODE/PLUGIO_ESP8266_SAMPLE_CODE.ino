
//////////////////////////////////// PLUGio IoT WEBSERVICES (We make IoT Easy) /////////////////////////////

///////////////////////////////////// THE SERVICES ARE POWERED BY IoTics.Net  /////////////////////////

//////////////////////////////////////  COPYRIGHT © IoTics.Net 2020 (www.iotics.net) ///////////////////

////////////////////////////////  ESP8266 SAMPLE CODE  ////// IF YOU FACE ANY ISSUE WHILE COMPILING THE CODE THEN ONLY ==>
				
///////////////////////////////////// USE ESP8266 BOARD MANAGER VERSION 2.3.0 for BEST EXPERIENCE   /////////////////

///////////////////////////////////////////// just go to Tools->Board->Board Manager
//////////////////////////////////////////////Search for esp8266. ( which is created by ESP8266 Community )
//////////////////////////////////////////////Change the version to 2.3.0.
//////////////////////////////////////////////Install and you are ready to rock.


#include <plugio.h>
#include <ESP8266WiFi.h>
char ssid[]= "XXXXXXXXXX";
char password[]= "XXXXXXXXXX";

char dev_id[]= "XXXXXXXXXX";         // only for nestio
char nestioUser_id[]= "XXXXXXXXXX";  // only for nestio

char topicid[]= "XXXXXXXXXX";
char wkey[]= "XXXXXXXXXX";
char rkey[]= "XXXXXXXXXXXX";

plugio p =plugio();

void setup() {
  // wifi connection build up
WiFi.begin(ssid, password);
Serial.begin(115200);
while (WiFi.status() != WL_CONNECTED) {
    delay(50);

  Serial.print(".");

  }


Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
}

void loop() {
  
  // FORMAT TO COLLECT VIRTUAL SWITCH STATUS =>  nestioread(switch number <int>, device id , nestio user id)
  Serial.println(p.nestioRead(2,dev_id,nestioUser_id));
  
   //FORMAT TO UPDATE VIRTUAL SWITCH STATUS =>  nestioread(switch number <int>,switch status<int 1/0>, device id , nestio user id)
  Serial.println(p.nestioWrite(4,0,dev_id,nestioUser_id));
 
  // FORMAT TO WRITE PLUG_N_PLOT==>   p.plug_n_plot_write(topicid,write api key,THE PLOT SEQUENCE NUMBER (int){MAXIMUM 10 plots}, THE VALUE(int))
   Serial.println(p.plug_n_plot_write(topicid,wkey,3,random(1,100)));

   // FORMAT TO READ PLUG_N_PLOT==>   p.plug_n_plot_write(topicid,read api key),THE PLOT SEQUENCE NUMBER (int){MAXIMUM 10 plots})
   Serial.println(p.plug_n_plot_read(topicid,rkey,1));

///   MINIMUM 15 second delay is MANDATORY.
 delay(15000); 
 
}
