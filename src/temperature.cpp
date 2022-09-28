/*****************************************************************************
* @file temperature.cpp
* @brief Weather station source file for reading and processing temperature data
* @author Toby Godfrey
* @copyright
*****************************************************************************/

#include "ws.hpp"
#include "DallasTemperature.h"

bool isSetup = false;

double readTemperature(){
  return 0.0;
}

struct ReturnStatus setupTemperature(){
  try {
    OneWire oneWire(PIN_TEMPERATURE);
  } catch (int e) {
    return ReturnStatus(ERROR, &("Failed to create the OneWire object".c_str()));
  }

  try {
    DallasTemperature sensor(&oneWire);
    sensor.begin();
    readTemperature();
  } catch (int e) {
    return ReturnStatus(ERROR, &("Failed to start the sensor".c_str()));
  }

  isSetup = true;
  return ReturnStatus(OK, &("Temperature sensor successfully setup".c_str()));
}
