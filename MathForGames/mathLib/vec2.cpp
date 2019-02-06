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
	return sqrt(pow(x, 2) + pow(y, 2));
}

float vec2::dot(const vec2 & rhs) const
{
	return (x * rhs.x)+(y * rhs.y);
}

vec2 & vec2::normalize()
{
	float magnVar = magnitude();
	x /= magnVar;
	y /= magnVar;
	return *this;
}

vec2 vec2::getNormalized() const
{
	vec2 temp(x, y);
	float magnVar = temp.magnitude();
	temp.x /= magnVar;
	temp.y /= magnVar;
	return temp;
}

vec2 & vec2::scale(const vec2 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	vec2 temp(rhs.x, rhs.y);
	return temp;
}


float vec2::angleBetween(const vec2 & rhs) const
{
	vec2 normalize = getNormalized();
	vec2 rhs_normalize = rhs.getNormalized();
	return acos(normalize.dot(rhs_normalize));
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
