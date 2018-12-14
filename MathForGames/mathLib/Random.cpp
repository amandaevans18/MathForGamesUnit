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
	int seed;
	std::string converter;

	seed = pow(seed, 2);

	std::string convert = std::to_string(seed);
	if (isPowerOfTwo(sizeof(convert))) 
	{
		
	}
	else
	{

	}
	return;
}

