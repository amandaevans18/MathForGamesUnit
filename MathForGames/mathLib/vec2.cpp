#include "vec2.h"
#include <cfloat>
#include<cmath>

vec2::vec2()
{
	x = 0.0f;
	y = 0.0f;
}

vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}


float vec2::magnitude() const
{
	return 0.0f;
}

float vec2::dot(const vec2 & rhs) const
{
	return 0.0f;
}

vec2 & vec2::normalize()
{
	// TODO: insert return statement here
}

vec2 vec2::getNormalized() const
{
	return vec2();
}

vec2 & vec2::scale(const vec2 & rhs)
{
	// TODO: insert return statement here
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	vec2 temp(rhs.x, rhs.y);

	return temp;
}

vec2 vec2::getPerpCW() const
{
	return vec2();
}

vec2 vec2::getPerpCCW() const
{
	return vec2();
}

float vec2::angleBetween(const vec2 & rhs) const
{
	return 0.0f;
}


vec2 vec2::operator+(const vec2 & rhs) const
{
	vec2 temp;
	float y;
	float x;
	temp.x = rhs.x + x;
	temp.y = rhs.y + y;
	return temp;
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	vec2 temp;
	float y;
	float x;
	temp.x = rhs.x - x;
	temp.y = rhs.y - y;
	return temp;
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	vec2 temp;
	temp.x = rhs.x + rhs.x;
	temp.y = rhs.y + rhs.y;
	return temp;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	vec2 temp;
	temp.x = rhs.x - rhs.x;
	temp.y = rhs.y - rhs.y;
	return temp;
}

vec2 & vec2::operator*=(const float rhs)
{
	vec2 temp;
	temp.x = temp.x*rhs;
	temp.y = temp.y*rhs;

	return temp;
}

vec2 & vec2::operator/=(const float rhs)
{
	vec2 temp;
	temp.x = temp.x/rhs;
	temp.y = temp.y/rhs;

	return temp;
}


bool vec2::operator==(const float rhs) const
{
	if (rhs - rhs*(FLT_EPSILON) <= THRESHOLD)
	{	
		return true;
	}
	else
	{
		return false;
	}
}

bool vec2::operator!=(const float rhs) const
{
	if (rhs - rhs * (FLT_EPSILON) <= THRESHOLD)
	{
		return false;
	}
	else
	{
		return true;
	}
}


vec2 vec2::operator--() const
{
	vec2 temp;
	temp.x = temp.x - temp.x;
	temp.y = temp.y - temp.y;
	return temp;
}

float & vec2::operator[](size_t idx)
{
	if(idx == 0) 
	{
		return x;
	}
	else if (idx == 1) 
	{
		return y;
	}
}

float vec2::operator[](size_t idx) const
{
	if (idx == 0)
	{
		return x;
	}
	else if (idx == 1)
	{
		return y;
	}
}


vec2::operator const float*() const
{
	return &x;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 temp(rhs.x, rhs.y);
	temp.x = rhs.x * lhs;
	temp.y = rhs.y * lhs;

	return temp;
}
