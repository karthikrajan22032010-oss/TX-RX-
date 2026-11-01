#include <Keypad.h>
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

const byte ROWS = 4; /* four rows */
const byte COLS = 4; /* four columns */
/* define the symbols on the buttons of the keypads */
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {6, 7, 8, 9}; /* connect to the column pinouts of the keypad */

const char *one = "1";
const char *two = "2";
const char *three = "3";
const char *four = "4";
const char *five = "5";
const char *six = "6";
const char *seven = "7";
const char *eight = "8";
//TX PIN 12
char *Temp;
/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
Serial.begin(9600);
rf_driver.init();
Serial.println("Tx Started");
}

void loop(){
  char customKey = customKeypad.getKey();

  if (customKey){
    Serial.println(customKey);
    switch(customKey)
    {
      case '1':
      rf_driver.send((uint8_t *)one, strlen(one));
      rf_driver.waitPacketSent();      
      break;

      case '2':
      rf_driver.send((uint8_t *)two, strlen(two));
      rf_driver.waitPacketSent();      
      break;

      case '3':
      rf_driver.send((uint8_t *)three, strlen(three));
      rf_driver.waitPacketSent();      
      break;

      case '4':
      rf_driver.send((uint8_t *)four, strlen(four));
      rf_driver.waitPacketSent();      
      break;

      case '5':
      rf_driver.send((uint8_t *)five, strlen(five));
      rf_driver.waitPacketSent();      
      break;

      case '6':
      rf_driver.send((uint8_t *)six, strlen(six));
      rf_driver.waitPacketSent();      
      break;

      case '7':
      rf_driver.send((uint8_t *)seven, strlen(seven));
      rf_driver.waitPacketSent();      
      break;

      case '8':
      rf_driver.send((uint8_t *)eight, strlen(eight));
      rf_driver.waitPacketSent();      
      break;                                          
    }

  }

   // const char *msg = "Hello World";
   // rf_driver.send((uint8_t *)msg, strlen(msg));
   // rf_driver.waitPacketSent();
   // delay(1000);  
}