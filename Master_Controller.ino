/* File Name: Master Controller
 * Author: Marko Jurisic
 * Date Edited: 14th June 2021
 * 
 * Description: Master state machine which serves as top level controller for the DometiCAN.
 */

// Including all header files
 #include "Pin_Assignments.h"
 #include "Libraries.h"
 #include "CAN_Transceiver.h"
 #include "Wireless_Communications.h"
 #include "Datalink_Interface.h"
 
/* Function Name:Setup
 * Date Edited: 14th June 2021
 * 
 * Inputs: None
 * Outputs: None
 * Resources: None
 *
 * Description: Sets up each individual module
 */
void setup() {

  Serial.begin(9600); //Creates Serial port instance

  canTransceiverSetup(); // Sets up MCP2515 and MCP2551

  wifiSetup(); //Sets up Espressif8226

}


/* Function Name: Loop
 * Date Edited: 14th June 2021
 * 
 * Inputs: None
 * Outputs: None
 * Resources: None
 *
 * Description: Runs master state machine of the DometiCAN.
 */
void loop() {
 
}
