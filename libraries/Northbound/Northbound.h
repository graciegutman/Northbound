#ifndef __Norththbound_h__
#define __Northbound_h__
#define TOTAL_DEGREES 360
#define MOTORS 8

typedef struct Motor_Couple {
    int motor1;
    int motor2;
    int velocity1;
    int velocity2;
} Motor_Couple;

Motor_Couple degrees_to_motors(int degrees);

#endif
