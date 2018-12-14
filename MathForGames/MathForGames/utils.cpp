#include "utils.h"

int max(int a, int b)
{
	return  a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int clamp(int value, int min, int max)
{
	if (value > max)
	{
		return max;
	}
	else if (value < min)
	{
		return min;
	}
	else 
	{
		return value;
	}
}

int myAbs(int val)
{
	return 0 - val;
}

int pow(int base, int power)
{
	int result;
	for (int i = 0; i < power; i++) 
	{
		result = base * base;
	}
	return result;
}

int nextPowerOfTwo(int val)
{
	int temp = 1;
	while (temp<=val) 
	{
		temp *= 2;
	}
	return temp;
}

bool isPowerOfTwo(int val)
{
	return false;
}

float moveTowards(float current, float target, float maxDelta)
{
	
	return 0.0f;
}

int log(int val)
{
	return 0;
}
