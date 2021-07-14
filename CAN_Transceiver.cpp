/* File Name:CAN Transceiver
 * Author: Marko Jurisic
 * Date Edited: 14th June 2021
 * 
 * Description: Contains functions to allow transmission and receiving of CAN messages to and from a DUT.
 */

// Including all header files
#import <Arduino.h> 
#include "Pin_Assignments.h"
#include "Libraries.h"

float can_messages[/*TODO*/]={};

/* Function Name:CAN Transceiver Setup
 * Date Edited: 14th June 2021
 * 
 * Inputs: None
 * Outputs: None
 * Resources: None
 *
 * Description: Sets up the MCP2551 and MCP2515
 */
void canTransceiverSetup() {

    while (CAN_OK != CAN.begin(CAN_500KBPS))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }


}

/* Function Name:CAN Communications
 * Date Edited: 14th June 2021
 * 
 * Inputs: Pointer to an array containing all the CAN Messages.
 * Outputs: None
 * Resources: None
 *
 * Description: Receives and Transmits CAN messages from the DUT.
 */
void canComms(float can_messages){
    unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive())
    {
        CAN.readMsgBuf(&len, buf);

        unsigned long canId = CAN.getCanId();

        Serial.println("-----------------------------");
        Serial.print("Data from ID: 0x");
        Serial.println(canId, HEX);

        for(int i = 0; i<len; i++)
        {
            Serial.print(buf[i]);
            Serial.print("\t");
            if(ledON && i==0)
            {

                digitalWrite(ledPin, buf[i]);
                ledON = 0;
                delay(500);
            }
            else if((!(ledON)) && i==4)
            {

                digitalWrite(ledPin, buf[i]);
                ledON = 1;
            }
        }
        Serial.println();
    }
  
}
