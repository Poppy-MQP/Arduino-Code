/*******************************************************************************
* Copyright 2016 ROBOTIS CO., LTD.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/
#include <DynamixelShield.h>

#define DEBUG_SERIAL Serial2

const uint8_t DXL_ID = 0x02;
const float DXL_PROTOCOL_VERSION = 1.0;

//2 ,146, 77

DynamixelShield dxl;

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  // put your setup code here, to run once:
  
  // For Uno, Nano, Mini, and Mega, use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(115200);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_POSITION);
  //dxl.torqueOn(DXL_ID);
   
}

//225,229, 227

void loop() {
  // put your main code here, to run repeatedly:
  
  // Please refer to e-Manual(http://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/) for available range of value. 
  // Set Goal Position in RAW value
  //dxl.setGoalPosition(DXL_ID, 20, UNIT_DEGREE);
  delay(1000);
  // Print present position in raw value
  DEBUG_SERIAL.print("Present Position(raw) : ");
  DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID));
  delay(1000);

  // Set Goal Position in DEGREE value
  //dxl.setGoalPosition(DXL_ID, 60, UNIT_DEGREE);
  delay(1000);
  // Print present position in degree value
  DEBUG_SERIAL.print("Present Position(degree) : ");
  DEBUG_SERIAL.println(dxl.getPresentPosition(DXL_ID, UNIT_DEGREE));
  delay(1000);
}
