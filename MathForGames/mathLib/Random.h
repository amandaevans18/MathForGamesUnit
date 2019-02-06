#pragma once
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

template <typename T>
class random 
{
private:
	int origSeed;//the original seed
	int currentSeed;//the current (most edited seed)
	int seedLength;//lenght of the seed
	int factor; //Used to factor the random #
	const uint64_t weylbs = 0xb5ad4eceda1ce2a9; // qualifying seed
public:
	random();
	T rand(T min, T max);
	T randomDec(T min, T max);
	void randomSeed(int seedVal);
	int getRandomSeed();

};

template<typename T>
 random<T>::random()
{
	 origSeed = 10000;
	 seedLength = 6;
}

 template<typename T>
  T random<T>::rand(T min, T max)
 {
	  T temp = currentSeed * currentSeed;
	  factor += weylbs;
	  temp += weylbs;
	  string seedString = to_string(temp);
	  seedString.erase(0, (seedString.length() - seedLength) / 2);
	  seedString.erase(seedLength);
	  currentSeed = stoi(seedString, 0, 10);
	  return fmod(currentSeed, (max - min + 1)) + min;

  }

 template<typename T>
  T random<T>::randomDec(T min, T max)
 {
	  T temp = cRand(0, INT_MAX);
	  for (float i = 0; i < cRand(0, seedLength); i++)
	  {
		  temp /= 10;
	  }
	  return fmod(temp, (max - min + 1)) + min;
 }

 template<typename T>
  void random<T>::randomSeed(int seedVal)
 {
	  seedLength = 6;
	  seedVal = stoi(to_string(seedVal).erase(0, to_string(seedVal).length() - seedLength), 0, 10);
	  origSeed = seedVal;
	  origSeed = currentSeed;
	  
 }

 template<typename T>
  int random<T>::getRandomSeed()
 {
	 return origSeed;
 }
