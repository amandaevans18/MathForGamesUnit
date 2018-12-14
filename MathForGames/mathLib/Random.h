#pragma once
struct numberGenerator 
{
	size_t number;

	size_t getNumberForSeed(size_t min);
};


// returns a random value between min and max
template< typename T>
T rand(T min, T max) 
{

}


// returns a random value between min and max
//  - the value may contain decimal components
template< typename T>
T randDecimal(T min, T max) 
{

}


// seed the random number generator
void seedRand(int seedValue);

// returns the seed used for the random number generator
int getRandSeed(int number);

