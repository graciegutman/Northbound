#include <Wire.h>
#include "Adafruit_DRV2605_F2.h"
#include "Magsensor.h"
#include "Northbound.h"
#define TCAADDR 0x70

Adafruit_HMC5883_Unified mag(255);

Adafruit_DRV2605_F2 drv0(TCAADDR, 0);
Adafruit_DRV2605_F2 drv1(TCAADDR, 1);
Adafruit_DRV2605_F2 drv2(TCAADDR, 2);
Adafruit_DRV2605_F2 drv3(TCAADDR, 3);
Adafruit_DRV2605_F2 drv4(TCAADDR, 4);
Adafruit_DRV2605_F2 drv5(TCAADDR, 5);
Adafruit_DRV2605_F2 drv6(TCAADDR, 6);
Adafruit_DRV2605_F2 drv7(TCAADDR, 7);

Adafruit_DRV2605_F2 drvs[8] {
    drv0, drv1, drv2, drv3, drv4, drv5, drv6, drv7
  };

void setup() {
  Serial.begin(9600);
  if(!mag.begin())
  {
     Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
     while(1);
  }
  for (int i=0; i<8; i++) {
    if (!drvs[i].begin()) 
    {
      Serial.print("Failed to initialize drv");
      Serial.print(i);
      Serial.print("\n");
      while(1);
    }
    drvs[i].setMode(DRV2605_MODE_REALTIME);
  }
}

void loop() {
  float degrees = headingDegrees(&mag);
  Motor_Couple motor_info = degrees_to_motors(degrees);
  Adafruit_DRV2605_F2 motor1 = drvs[motor_info.motor1];
  Adafruit_DRV2605_F2 motor2 = drvs[motor_info.motor2];
  for (int i=0; i<8; i++) {
    if (i != motor_info.motor1 && i != motor_info.motor2) {
      drvs[i].setRealtimeValue(0);
    }
  }
  motor1.setRealtimeValue(motor_info.velocity1);
  motor2.setRealtimeValue(motor_info.velocity2);
  delay(10);
}
