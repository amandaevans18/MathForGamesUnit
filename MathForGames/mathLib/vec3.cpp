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
	return sqrt(pow(x, 2) + pow(z, 2) + pow(y, 2));
}

float vec3::dot(const vec3 & rhs) const
{
	return ((x*rhs.x)+(y*rhs.y)+(z*rhs.z));
}
//TERRY I DONT REMEBER IF THIS IS WHAT YOU WANT
vec3 vec3::cross(const vec3 &rhs) const
{

	return { y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x };
}

vec3 & vec3::normalize()
{
	float tempMag = magnitude();
	x /= tempMag;
	y /= tempMag;
	z /= tempMag;
	return *this;
	
}

vec3 vec3::getNormalized()
{
	vec3 temp = *this;
	return  temp.getNormalized();
}

vec3 & vec3::scale(const vec3 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	return { x * rhs.x, y * rhs.y, z * rhs.z };
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	return { x + rhs.x, y + rhs.y, z + rhs.z };
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	return { x - rhs.x, y - rhs.y, z - rhs.z };
}

vec3 vec3::operator*(const float rhs) const
{
	return { x * rhs, y * rhs, z * rhs };
}

vec3 vec3::operator/(const float rhs) const
{
	return { x / rhs, y / rhs, z / rhs };
}


vec3 & vec3::operator+=(const vec3 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

vec3 & vec3::operator*=(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

vec3 & vec3::operator/=(const float rhs)
{
	x /= rhs;
	y /= rhs;
	z /= rhs;
	return *this;
}

bool vec3::operator==(const vec3 & rhs) const
{
	if ((x - rhs.x) < THRESHOLD && (y - rhs.y) < THRESHOLD && (z - rhs.z) < THRESHOLD)
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
	if ((x - rhs.x) < THRESHOLD && (y - rhs.y) < THRESHOLD && (z - rhs.z) < THRESHOLD)
	{
		return false;
	}
	else
	{
		return true;
	}
}

vec3::operator float *()
{
	return &x;
}


vec3::operator const float*() const
{
	return &x;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	return { rhs.x * lhs, rhs.y * lhs, rhs.z * lhs };
}
