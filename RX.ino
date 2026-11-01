#include <LiquidCrystal.h>

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
const int Relay1 = 2;
const int Relay2 = 3;
const int Relay3 = 4;
const int Relay4 = 5;
const int Relay5 = 6;
const int Relay6 = 7;
const int Relay7 = 8;
const int Relay8 = 9;
//RX PIN 11
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
{
    pinMode(Relay1, OUTPUT);
    pinMode(Relay2, OUTPUT);
    pinMode(Relay3, OUTPUT);
    pinMode(Relay4, OUTPUT);
    pinMode(Relay5, OUTPUT);
    pinMode(Relay6, OUTPUT);
    pinMode(Relay7, OUTPUT);
    pinMode(Relay8, OUTPUT);  
    digitalWrite(Relay1, HIGH);
    digitalWrite(Relay2, HIGH);
    digitalWrite(Relay3, HIGH);
    digitalWrite(Relay4, HIGH);
    digitalWrite(Relay5, HIGH);
    digitalWrite(Relay6, HIGH);
    digitalWrite(Relay7, HIGH);
    digitalWrite(Relay8, HIGH);

    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
    Serial.println("RX Started");


}
 
void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      switch(buf[0])
      {
        case 49:
        digitalWrite(Relay1, !digitalRead(Relay1));
        break;

        case 50:
        digitalWrite(Relay2, !digitalRead(Relay2));
        break;

        case 51:
        digitalWrite(Relay3, !digitalRead(Relay3));
        break;

        case 52:
        digitalWrite(Relay4, !digitalRead(Relay4));
        break;

        case 53:
        digitalWrite(Relay5, !digitalRead(Relay5));
        break;

        case 54:
        digitalWrite(Relay6, !digitalRead(Relay6));
        break;

        case 55:
        digitalWrite(Relay7, !digitalRead(Relay7));
        break;                        
 
        case 56:
        digitalWrite(Relay8, !digitalRead(Relay8));
        break;
      }
      Serial.print("Message Received: ");
      Serial.println(buf[0]);  
     // Serial.println((char*)buf);         
    }
}