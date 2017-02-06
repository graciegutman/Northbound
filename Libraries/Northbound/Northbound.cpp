#include "Northbound.h"
#include <math.h>

Motor_Couple degrees_to_motors(int degrees) {
    double divisor = MOTORS / TOTAL_DEGREES;
    int m1 =  degrees/TOTAL_DEGREES;
    int m2 = m1 + 1 % MOTORS;
    // 100 is some arbitrary maximum value 
    int v1 = 100 - (int)(100 * (fmod((double)degrees, divisor) / (double)divisor));
    int v2 = (int)(100 * (fmod((double)degrees, divisor) / (double)divisor));
    Motor_Couple mc = {m1, m2, v1, v2};
    return mc;
}


