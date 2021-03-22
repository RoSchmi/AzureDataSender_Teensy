# AzureDataSender_Teensy

Sending Sensor Data to Azure Storage Tables using Board Teensy 4.1.
This is work in progress, actually works but isn't tested over longer time periods

For details about the functions of this app how to use it have a look on this project
https://github.com/RoSchmi/AzureDataSender_Wio_Terminal
https://www.hackster.io/RoSchmi/wio-terminal-app-sending-sensor-data-to-azure-storage-tables-dbb08e

### Patches for Teensy 4.1 board
There are two hacks which are needed to achieve that this application works on the Teensy 4.1:
1) The used Stream.h header file has to be changed:
   Go to C:/Users/thisUser/.platformio/packages/framework-arduinoteensy/cores/teensy4/Stream.h
   and exchange the Stream.h file with the Stream.h file found in the folder /lib/RoSchmi/Stream/ of this repository
   
2) For Teensyduino v1.53 the libraries 'FNET' and 'NativeEthernet' in C:\Users\thisuser\.platformio\packages\framework-arduinoteensy\libraries have to be exchanged with the        latest (act. 22.03.2021) libraries of 
   -https://github.com/vjmuzik/NativeEthernet#master
   and -https://github.com/vjmuzik/FNET#master 
   Then in the FNET library the file fnet_dns.c has to be altered. Otherwise DNS resolving of the Azure Storage url doesn't work
   Go to FNET/src/service/dns/fnet_dns.c and change the method 'static fnet_bool_t _fnet_dns_cmp_name(const char *rr_name, const char *name)'
   to ignore the result of this test (but be aware of the security risk of DNS-spoofing)
   
      if(i == name_length)
      { result = FNET_TRUE; }    
      else {
      result = FNET_TRUE;
       //result = FNET_FALSE;
      }
