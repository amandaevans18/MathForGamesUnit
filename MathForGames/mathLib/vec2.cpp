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
	vec2 temp(x, y);
	float magnVar = temp.magnitude();
	temp.x /= magnVar;
	temp.y /= magnVar;
	return temp;
}

vec2 vec2::getNormalized() const
{
	vec2 temp = *this;
	temp.normalize();
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
	vec2 temp(x*rhs.x, y*rhs.y);

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
	return { x + rhs.x, y + rhs.y };
}

vec2 vec2::operator-(const vec2 & rhs) const
{

	return { x - rhs.x, y - rhs.y };
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

vec2 & vec2::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

vec2 & vec2::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	return *this;
}


bool vec2::operator==(const vec2 rhs) const
{
	if ((x - rhs.x) < THRESHOLD && (y - rhs.y) < THRESHOLD)
	{	
		return true;
	}
	else
	{
		return false;
	}
}

bool vec2::operator!=(const vec2 rhs) const
{
	if ((x - rhs.x) < THRESHOLD && (y - rhs.y) < THRESHOLD)
	{
		return false;
	}
	else
	{
		return true;
	}
}

vec2::operator float *()
{
	return &x;
}


vec2::operator const float*() const
{
	return &x;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	return { rhs.x * lhs, rhs.y * lhs };
}
