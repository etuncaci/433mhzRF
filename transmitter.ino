/*.............................................................
Sending Multiple Variables Using VirtualWire. Transmitter Code
..............................................................*/
#include <VirtualWire.h>
 
int Sensor1Pin = A1;// The pins were sensor are attached
int Sensor2Pin = A2;
int Sensor3Pin = A3;
int Sensor4Pin = A4;
int Sensor5Pin = A5;
int Sensor6Pin = A6;

int ledPin = 13;
int Sensor1Data;// The variable were the data from each sensor
int Sensor2Data;// will be stored
int Sensor3Data;
int Sensor4Data;
int Sensor5Data;
int Sensor6Data;
char Sensor1CharMsg[31];// The string that we are going to send trought rf
 
void setup() {
 
 // LED
 pinMode(ledPin,OUTPUT);
  
 // Sensor(s)
 pinMode(Sensor1Pin,INPUT);
 pinMode(Sensor2Pin,INPUT);
 pinMode(Sensor3Pin,INPUT);
 pinMode(Sensor4Pin,INPUT);
 pinMode(Sensor5Pin,INPUT);
 pinMode(Sensor6Pin,INPUT);
  
 // VirtualWire setup
 vw_setup(2000); // Bits per sec
 
 // Set the Tx pin. Default is 12
 vw_set_tx_pin(12);
 
}
 
void loop() {
   
  // Read and store Sensor Data
  Sensor1Data = analogRead(Sensor1Pin);
  Sensor2Data = analogRead(Sensor2Pin);
  Sensor3Data = analogRead(Sensor3Pin);
  Sensor4Data = analogRead(Sensor4Pin);
  Sensor5Data = analogRead(Sensor5Pin);
  Sensor6Data = analogRead(Sensor6Pin);
   
  //sprintf(Sensor1CharMsg, "%d,%d,%d,%d,", Sensor1Data, Sensor2Data, Sensor3Data, Sensor4Data);
    sprintf(Sensor1CharMsg, "%d,%d,%d,%d,%d,%d,", Sensor1Data, Sensor2Data, Sensor3Data, Sensor4Data, Sensor5Data, Sensor6Data);

  
 // Turn on a light to show transmitting
 vw_send((uint8_t *)Sensor1CharMsg, strlen(Sensor1CharMsg));
 vw_wait_tx(); // Wait until the whole message is gone
 // Turn off a light after transmission
 delay(40);
 
}
