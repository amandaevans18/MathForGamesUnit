#pragma once
//defined as Pi
const float PI = 3.14159;
//angle measure expressed in degrees to get equivalent in radians 
const float DEG_TO_RAD = 0.017;
//angle measure expressed in radians to get its equivalent in degrees
const float RAD_TO_DEG = 57.29;

//returns the max of two ints
int max(int a, int b);

//returns the minium of two ints
int min(int a, int b);

//returns a no smaller than min and no larger than max
int clamp(int value, int min, int max);

//returns the absolute value of val
int myAbs(int val);

//returns base to the power of exp
int pow(int base, int power);

//returns the next power of two after the given value (the behavior of this function if the next power of two is beyond range of int is not defined.
int nextPowerOfTwo(int val);

//returns true if the value is a power of two otherwise returns false
bool isPowerOfTwo(int val);

//moves the current value towards the target value. The maxium change should not exceed maxDelta.
float moveTowards(float current, float target, float maxDelta);
