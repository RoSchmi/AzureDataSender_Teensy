# AzureDataSender_Teensy

Sending Sensor Data to Azure Storage Tables using Teensy 4.1.
Works with http- and https- transmission, isn't yet tested over longer time periods

For details about the functions of this app and how to use and apply settings have a look on this similar project

https://www.hackster.io/RoSchmi/wio-terminal-app-sending-sensor-data-to-azure-storage-tables-dbb08e

### Patches for Teensy 4.1 board
There are two hacks which are needed to achieve that this application works on the Teensy 4.1:
1) The used Stream.h header file has to be changed:
   Go to C:/Users/thisUser/.platformio/packages/framework-arduinoteensy/cores/teensy4/Stream.h
   and exchange the Stream.h file with the Stream.h file found in the folder /lib/RoSchmi/Stream/ of this repository
   
2) For Teensyduino v1.53 the libraries 'FNET' and 'NativeEthernet' in C:\Users\thisuser\.platformio\packages\framework-arduinoteensy\libraries have to be exchanged with the latest (actual 02. April 2021) libraries of 
   -https://github.com/vjmuzik/NativeEthernet#master
   and -https://github.com/vjmuzik/FNET#master 
   
   Then in the FNET library the file fnet_dns.c has to be altered. Otherwise DNS resolving of the Azure Storage url doesn't work.
   Go to  FNET/src/service/dns/fnet_dns.c and comment the line
   
   //'if(_fnet_dns_cmp_name(rr_name, dns_if->host_name) == FNET_TRUE)'
   
   // {
   
   and the corresponding closing brace

   or use (already selected in platformio.ini)
   -https://github.com/RoSchmi/FNET#devRoSchmi
   where these changes are already included
   
  
