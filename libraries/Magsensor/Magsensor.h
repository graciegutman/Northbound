#ifndef __MAGSENSOR_H__
#define __MAGSENSOR_H__

#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>
#include <Wire.h>

float headingDegrees(Adafruit_HMC5883_Unified *mag);
#endif
