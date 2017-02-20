#include <Magsensor.h>

float headingDegrees(Adafruit_HMC5883_Unified *mag) {
  sensors_event_t event; 
  mag->getEvent(&event);
  Serial.print("X: "); Serial.print(event.magnetic.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.magnetic.z); Serial.print("  ");Serial.println("uT");

  float heading = atan2(event.magnetic.y, event.magnetic.x);

  //float declinationAngle = 0.22;
  //heading -= declinationAngle;

  if(heading < 0)
    heading += 2*PI;

  if(heading > 2*PI)
    heading -= 2*PI;

  float headingDegrees = heading * 180/M_PI; 
  return headingDegrees;
} 
