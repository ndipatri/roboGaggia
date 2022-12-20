#ifndef HEATER_H
#define HEATER_H

#include <pid.h>
#include "Common.h"

extern double TARGET_BREW_TEMP; 

extern double TARGET_STEAM_TEMP; 

struct HeaterState {
  boolean thermocoupleError = false;  

  // current temp
  // this is  updated as we read thermocouple sensor
  double measuredTemp;
  
  // This is calculated and updated by the PID
  double heaterShouldBeOn;

  // Used to track ongoing heat cycles...
  float heaterStarTime = -1;

  // The control system for determining when to turn on
  // the heater in order to achieve target temp
  PID *heaterPID;

};

extern HeaterState heaterState;

void heaterInit();

void readBrewHeaterState();

void readSteamHeaterState();

boolean shouldTurnOnHeater();

void configureBrewHeater();
void configureSteamHeater();

boolean isHeaterOn();

void turnHeaterOn();

void turnHeaterOff();

#endif