
#ifndef plugio_h

                                  
#define plugio_h


#include "Arduino.h"


class plugio{

  
  public:
  
   
    plugio();
    
      
    String nestioRead(int s, String dev_id, String nestioUserid);
    String nestioWrite(int s, int m,String dev_id, String nestioUserid);
  String plug_n_plot_write(String topic_id, String w_key, int plot, int val); 
  String plug_n_plot_read(String topic_id, String r_key, int plot); 
    

  private:                  
    
    
    String _ssid, _pass, _pinThree;
};


#endif


// SANDIPAN CHAKRABORTY (AUTHOR) (FOUNDER IoTics.Net)
