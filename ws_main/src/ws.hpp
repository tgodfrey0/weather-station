/*****************************************************************************
* @file ws.h
* @brief Weather station header
* @author Toby Godfrey
* @copyright
*****************************************************************************/

#ifndef WS_HPP
#define WS_HPP

#include <Arduino.h>
#include <mcp_can.h>

// Constants
#define SEN_TEMP_PIN 9999

#define COMMS__SERIAL_BAUD   115200

// Structs
struct weatherFrame { //! Union?
  /*
     Time
     Temperature
     Humidity
     Pressure
     Location enum (inside or outside)
     */
};

// Methods
void can_init();
void can_process();
struct canFrame readCanFrame();
void sendCanFrame(struct canFrame canFrame);

#endif // WS_HPP
