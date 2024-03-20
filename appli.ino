/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.10 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.13.1 or later version;
     - for iOS 1.10.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>


// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600


#include <RemoteXY.h>

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 107 bytes
  { 255,3,0,4,0,100,0,17,0,0,0,24,2,106,200,200,84,1,1,4,
  0,4,44,71,20,87,118,33,20,61,48,203,16,1,11,157,24,24,21,43,
  25,25,0,135,31,103,97,117,99,104,101,0,71,22,8,65,65,84,4,41,
  41,56,0,36,31,135,0,0,32,193,0,0,32,65,0,0,32,65,0,0,
  160,64,0,0,128,63,31,0,1,73,155,24,24,148,43,26,26,0,1,31,
  100,114,111,105,116,101,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t slider; // =-100..100 slider position
  uint8_t gauche; // =1 if button pressed, else =0
  uint8_t droite; // =1 if button pressed, else =0

    // output variables
  float afficheur; // from -10 to 10

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////



void setup() 
{
  RemoteXY_Init (); 
  
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}
