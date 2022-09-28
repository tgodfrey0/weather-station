/*****************************************************************************
* @file ws.hpp
* @brief Weather station header
* @author Toby Godfrey
* @copyright
*****************************************************************************/

#ifndef WS_HPP
#define WS_HPP

#include <Arduino.h>
#include <stdint.h>
#include <string.h>

// Constants
#define COMMS__SERIAL_BAUD   115200
#define PIN_TEMPERATURE      1
#define PIN_HUMIDITY         2
#define PIN_PRESSURE         3

// Enums
enum Location {
  INSIDE,
  OUTSIDE,
};

enum ReturnCode {
  OK = 0,
  ERROR = -1,
};

// Structs

struct weatherFrame {
  /*
     Time
     Temperature
     Humidity
     Pressure
     Location enum (inside or outside)
     */
  struct DateTime *dateTime;
  double *temperature;
  double *humidity;
  double *pressure;
  enum Location *location;

};

struct DateTime {
  uint8_t seconds;
  uint8_t minutes;
  uint8_t hours;
  uint8_t day;
  uint8_t month;
  uint16_t year;
};

struct ReturnStatus {
  enum ReturnCode status;
  char* msg;
};

// Methods
struct ReturnStatus setupTemperature();
struct ReturnStatus setupPressure();
struct ReturnStatus setupHumidity();
struct ReturnStatus setupDisplay();

double readTemperature();
double readPressure();
double readHumidity();
void display();

void ws_init();
void ws_run();

#endif // WS_HPP
