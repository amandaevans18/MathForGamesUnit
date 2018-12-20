#include "Random.h"
#include"utils.h"
#include<string>


size_t numberGenerator::getNumberForSeed(size_t min)
{
	std::string lengthOfVari;
	for (int i = 0; sizeof(lengthOfVari) < 6; i++)
	{
		number += pow(min, i);
		lengthOfVari = std::to_string(number);
	}
	return number;
}

void seedRand(int seedValue)
{
}

int getRandSeed(int number)
{
	int seed = number;
	int idx;
	std::string converted;

	seed = pow(seed, 2);

	std::string convert = std::to_string(seed);
	if (isPowerOfTwo(sizeof(convert))) 
	{
		for (int i = 0; i < sizeof(convert); i++) 
		{
			if (i == 0 || i == sizeof(convert)) 
			{
				
			}
			else 
			{
				convert[i] += converted[idx];
				idx++;
			}
		}
	}
	else
	{

	}
	return seed;
}

