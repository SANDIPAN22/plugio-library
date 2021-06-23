#include "Arduino.h"





#if defined(ESP8266)
#include <ESP8266HTTPClient.h>
#pragma message "ESP8266 stuff happening!"
#elif defined(ESP32)
#include <HTTPClient.h>
#pragma message "ESP32 stuff happening!"
#else
#error "This ain't a ESP8266 or ESP32, dumbo!"
#endif



//This will include the Header File so that the Source File has access
//  to the function definitions in the myFirstLibrary library.
#include "plugio.h" 

//  This is where the constructor Source Code appears. The '::' indicates that
//  it is part of the myFirstLibrary class and should be used for all constructors
//  and functions that are part of a class.
plugio::plugio(){

Serial.println("WELCOME TO PLUGIO WEB SERVICES ! WE MAKE IOT EASY FOR YOU !");

  
}



String plugio::nestioRead(int s, String dev_id, String nestioUserid){
	delay(15000);
 HTTPClient http1;  //Declare an object of class HTTPClient
 String api1="http://nestio.iotics.net/nestioRead.php?s="+String(s,DEC)+"&nestUserid="+nestioUserid+"&dev_id=";
   
   
    api1=api1+dev_id;
      http1.begin(api1);
    Serial.println("NESTio READ ==> ");
int httpCode1 = http1.GET();                                                            
 String payload1;
if (httpCode1 > 0) { //Check the returning code
 
 payload1 = http1.getString();   //Get the request response payload

}
http1.end();
  return (payload1);             
}

String plugio::plug_n_plot_write(String topic_id, String w_key, int plot, int val){
  delay(15000);
  HTTPClient http2;
  String api2="http://plugnplot.iotics.net/pnpin.php?";
  String con="";
  switch(plot)
  {
    case 1:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }

      case 2:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }

      case 3:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }

      case 4:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }

      case 5:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }

       case 6:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }
        case 7:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }
        case 8:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }
        case 9:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }
        case 10:
    {
      
    con="f"+String(plot,DEC)+"="+String(val,DEC)+"&";
    break;
      }
      default:
      {
        Serial.println("Wrong Plot sequence Number! It should be in [1,2,3,4,5]");
        }
    
    }
 
   
    api2+=con;
    
   api2+="&topicid="+topic_id+"&wkey="+w_key;
   Serial.println("Plug_n_Plot WRITE ==> ");
  http2.begin(api2);
  int httpCode2= http2.GET();
  String payload2;
  if (httpCode2>0)
  {
    payload2=http2.getString();
  }
  http2.end();
  return (payload2);
  
}


String plugio::nestioWrite(int s, int m,String dev_id, String nestioUserid){
 delay(15000);
 HTTPClient http3;  //Declare an object of class HTTPClient
 String api3="http://nestio.iotics.net/csvWrite.php?s="+String(s,DEC)+"&m="+String(m,DEC)+"&nestUserid="+nestioUserid+"&dev_id=";
   
   
    api3=api3+dev_id;
      http3.begin(api3);
     Serial.println("NESTio WRITE ==> ");
int httpCode3 = http3.GET();                                                            
 String payload3;
if (httpCode3 > 0) { //Check the returning code
 
 payload3 = http3.getString();   //Get the request response payload

}
http3.end();
  return (payload3);             
}

String plugio::plug_n_plot_read(String topic_id, String r_key, int plot){
 delay(15000);
 HTTPClient http4;  //Declare an object of class HTTPClient
 String api4="http://plugnplot.iotics.net/pnpout.php?topicid="+topic_id+"&rkey="+r_key+"&f="+String(plot,DEC);
   
   
    
      http4.begin(api4);
   Serial.println("Plug_n_PloT READ ==> ");
int httpCode4 = http4.GET();                                                            
 String payload4;
if (httpCode4 > 0) { //Check the returning code
 
 payload4 = http4.getString();   //Get the request response payload

}
http4.end();
  return (payload4);             
}



// SANDIPAN CHAKRABORTY (AUTHOR) (FOUNDER IoTics.Net)
