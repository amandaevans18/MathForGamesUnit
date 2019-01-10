#include "utils.h"
#include<climits>

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
	int counter = INT_MIN;
	while (counter < INT_MAX)
	{
		if (val == counter)
		{
			return true;
		}
		counter += 2;
	}
		return false;
	
}


float moveTowards(float current, float target, float maxDelta)
{
	while (current != target && current < maxDelta) 
	{
		current += 1.0f;
	}
	return current;
}
