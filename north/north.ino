#include <Wire.h>
#include "Adafruit_DRV2605_F.h"
#include "Northbound.h"

Adafruit_DRV2605 drv0(0x70);
Adafruit_DRV2605 drv1(0x71);
Adafruit_DRV2605 drv2(0x72);
Adafruit_DRV2605 drv3(0x73);
Adafruit_DRV2605 drv4(0x74);
Adafruit_DRV2605 drv5(0x75);
Adafruit_DRV2605 drv6(0x76);
Adafruit_DRV2605 drv7(0x77);

Adafruit_DRV2605 drvs[8] {
    drv0, drv1, drv2, drv3, drv4, drv5, drv6, drv7
};

/* TODO STILL:
Set up magnetometer
Make a high-level mag read func
*/

void setup() {
  Serial.begin(9600);
  for (int i=0; i<8; i++) {
    (drvs[i]).setMode(DRV2605_MODE_REALTIME);
  };
}

void loop() {
  // Read off magnetometer eventually, but for now, just loop thru degrees
  for (int i=0; i<360; i++) {
      Motor_Couple motor_info = degrees_to_motors(i);
      Adafruit_DRV2605 motor1 = drvs[motor_info.motor1];
      Adafruit_DRV2605 motor2 = drvs[motor_info.motor2];
      motor1.setRealtimeValue(motor_info.velocity1);
      motor2.setRealtimeValue(motor_info.velocity2);
      delay(200);
    };
}
