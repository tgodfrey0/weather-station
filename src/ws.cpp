/*****************************************************************************
* @file ws.cpp
* @brief The main weather station source file
* @author Toby Godfrey
* @copyright
*****************************************************************************/

#include "ws.hpp"

void ws_init(){
  Serial.begin(COMMS__SERIAL_BAUD);
  std::cout << setupTemperature().msg << std::endl;
}
