/*.............................................................
Sending Multiple Variables Using VirtualWire. Receiver Code
..............................................................*/
#include <VirtualWire.h>
  
// Sensors
int Sensor1Data;
int Sensor2Data;
int SensorData3;
int SensorData4;

int SensorData5;
int SensorData6;


char StringReceived[32]; //
  
  
  
void setup() {
    // VirtualWire
    // Initialise the IO and ISR
    // Required for DR3100
  //Serial.begin(9600);
    // Bits per sec
    vw_setup(2000);
    vw_set_rx_pin(11); 
      
    // Start the receiver PLL running
    vw_rx_start();      
  
} // END void setup
  
void loop(){
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
      
//Taking the data from the control base
    if (vw_get_message(buf, &buflen))
    {
      digitalWrite(13,HIGH);
      
 int i;
        // Message with a good checksum received, dump it.
        for (i = 0; i < buflen; i++)
 {           
          // Fill Sensor1CharMsg Char array with corresponding
          // chars from buffer.  
          StringReceived[i] = char(buf[i]);
 }
  
      //sscanf(StringReceived, "%d,%d,%d,%d,%d,%d",&Sensor1Data, &Sensor2Data,&SensorData3,&SensorData4); // Converts a string to an array
        sscanf(StringReceived, "%d,%d,%d,%d,%d,%d,%d,%d",&Sensor1Data, &Sensor2Data,&SensorData3,&SensorData4,&SensorData5,&SensorData6); // Converts a string to an array

      
          
        // Turn off light to and await next message
         //Serial.print(Sensor1Data);  Serial.print("\t");
         //Serial.print(Sensor2Data);  Serial.print("\t");
         //Serial.print(SensorData3);  Serial.print("\t");
         //Serial.print(SensorData4);  Serial.print("\t");
         //Serial.print(SensorData5);  Serial.print("\t");
         //Serial.println(SensorData6);
    }
  
 memset( StringReceived, 0, sizeof( StringReceived));// This line is for reset the StringReceived
}
