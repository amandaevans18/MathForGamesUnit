#include "vec3.h"
#include <cfloat>
#include<cmath>

vec3::vec3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float vec3::magnitude() const
{
	return 0.0f;
}

float vec3::dot(const vec3 & rhs) const
{
	return (x*rhs.x)+(y*rhs.y)+(z*rhs.z);
}

vec3 vec3::cross(const vec3 & rhs) const
{
	vec3 temp;
	temp.x = (y * rhs.z) - (z * rhs.y);
	temp.y = (z * rhs.x) - (x * rhs.z);
	temp.z = (x * rhs.y) - (y * rhs.x);
	return ;
}

vec3 & vec3::normalize()
{
	// TODO: insert return statement here
}

vec3 vec3::getNormalised()
{
	return vec3();
}

vec3 & vec3::scale(const vec3 & rhs)
{
	// TODO: insert return statement here
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	return vec3();
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	vec3 temp;
	float y;
	float x;
	float z;
	temp.x = rhs.x + x;
	temp.y = rhs.y + y;
	temp.z = rhs.z + z;
	return temp;
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	vec3 temp;
	float y;
	float x;
	float z;
	temp.x = rhs.x - x;
	temp.y = rhs.y - y;
	temp.z = rhs.z - z;
	return temp;
}

vec3 vec3::operator*(const float rhs) const
{
	vec3 temp;
	temp.x = temp.x * rhs;
	temp.y = temp.y * rhs;
	temp.z = temp.z * rhs;
	return temp;
}

vec3 vec3::operator/(const float rhs) const
{
	vec3 temp;
	temp.x = temp.x / rhs;
	temp.y = temp.y / rhs;
	temp.z = temp.z / rhs;
	return temp;
}


vec3 & vec3::operator+=(const vec3 & rhs)
{
	vec3 temp;
	temp.x = rhs.x + rhs.x;
	temp.y = rhs.y + rhs.y;
	temp.z = rhs.z + rhs.z;
	return temp;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	vec3 temp;
	temp.x = rhs.x - rhs.x;
	temp.y = rhs.y - rhs.y;
	temp.z = rhs.z - rhs.z;
	return temp;
}

vec3 & vec3::operator*=(const float rhs)
{
	vec3 temp;
	temp.x = temp.x * rhs;
	temp.y = temp.y * rhs;
	temp.z = temp.z * rhs;
	return temp;
}

vec3 & vec3::operator/=(const float rhs)
{
	vec3 temp;
	temp.x = temp.x / rhs;
	temp.y = temp.y / rhs;
	temp.z = temp.z / rhs;
	return temp;
}

bool vec3::operator==(const vec3 & rhs) const
{
	if (rhs.x - rhs.x * (FLT_EPSILON) <= THRESHOLD && rhs.y - rhs.y * (FLT_EPSILON) <= THRESHOLD&& rhs.z - rhs.z * (FLT_EPSILON) <= THRESHOLD)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool vec3::operator!=(const vec3 & rhs) const
{
	if (rhs.x - rhs.x * (FLT_EPSILON) <= THRESHOLD && rhs.y - rhs.y * (FLT_EPSILON) <= THRESHOLD && rhs.z - rhs.z * (FLT_EPSILON) <= THRESHOLD)
	{
		return false;
	}
	else
	{
		return true;
	}
}

vec3 vec3::operator--() const
{
	vec3 temp;
	temp.x = temp.x - temp.x;
	temp.y = temp.y - temp.y;
	temp.z = temp.z - temp.z;
	return temp;
}

vec3::operator const float*() const
{
	return &x;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 temp(rhs.x, rhs.y, rhs.z);
	temp.x = rhs.x * lhs;
	temp.y = rhs.y * lhs;
	temp.z = rhs.z * lhs;
	return temp;
}
