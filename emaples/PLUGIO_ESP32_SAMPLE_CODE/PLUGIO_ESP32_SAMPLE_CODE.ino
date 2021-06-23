
//////////////////////////////// PLUGio IoT WEBSERVICES (We make IoT Easy) /////////////////////////////

////////////////////////////////// THE SERVICES ARE POWERED BY IoTics.Net  /////////////////////////

//////////////////////////////////////  COPYRIGHT © IoTics.Net 2020 (www.iotics.net) ///////////////////


#include <plugio.h>
#include <WiFi.h>

const char* ssid = "XXXXXXXXXX";  
const char* password = "XXXXXXXXXX"; 
const char* dev_id = "XXXXXXXXXX";                // only for nestio
const char* nestioUser_id = "XXXXXXXXXX";         // only for nestio
const char* topicid = "XXXXXXXXXX"; // 
const char* wkey = "XXXXXXXXXX";
const char* rkey = "XXXXXXXXXXX";

/// plugio instantiniate
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
  //TO COLLECT VIRTUAL SWITCH STATUS =>  nestioread(switch number <int>, device id<char array> , nestio user id<char array>)
  Serial.println(p.nestioRead(2,dev_id,nestioUser_id));
  
   //TO UPDATE VIRTUAL SWITCH STATUS =>  nestioread(switch number <int>,switch status<int 1/0>, device id <char array>, nestio user id<char array>)
  Serial.println(p.nestioWrite(2,1,dev_id,nestioUser_id));
  
  // FORMAT TO WRITE PLUG_N_PLOT==>   p.plug_n_plot_write(topicid(char array),write api key(char array),THE PLOT SEQUENCE NUMBER (int){MAXIMUM 10 plots}, THE VALUE(int))
  Serial.println(p.plug_n_plot_write(topicid,wkey,3,random(1,100)));

   // FORMAT TO READ PLUG_N_PLOT==>   p.plug_n_plot_write(topicid,read api key),THE PLOT SEQUENCE NUMBER (int){MAXIMUM 10 plots})
   Serial.println(p.plug_n_plot_read(topicid,rkey,1));


///   MINIMUM 15 second delay is MANDATORY.
 delay(15000); 
}
