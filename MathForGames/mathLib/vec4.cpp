#include "vec4.h"
#include <cmath>
#include <cfloat>

vec4::vec4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	t = 0.0f;
}

vec4::vec4(float _x, float _y, float _z, float _t)
{
	x = _x;
	y = _y;
	z = _z;
	t = _t;
}

float vec4::magnitude() const
{
	return sqrt(x * x + y * y + z * z + t * t);
}

float vec4::dot(const vec4 & rhs) const
{
	return (x *rhs.x)+(y *rhs.y)+(z*rhs.z)+(t*rhs.t);
}

vec4 vec4::cross(const vec4 & rhs) const
{
	vec4 temp;
	temp.x = (y * rhs.z * rhs.t) - (z * rhs.y * rhs.t);
	temp.y = (z * rhs.x * rhs.t) - (x * rhs.z* rhs.t);
	temp.z = (x * rhs.y * rhs.t) - (y * rhs.x * rhs.t);
	temp.t = 0;
	return temp;
}

vec4 & vec4::normalize()
{
	float magn = magnitude();
	x /= magn;
	y /= magn;
	z /= magn;
	t /= magn;
	return *this;
}
vec4 vec4::getNormalized()
{
	return { x / magnitude(), y / magnitude(), z / magnitude(), t / magnitude() };
}

vec4 & vec4::scale(const vec4 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	t *= rhs.t;
	return *this;
}

vec4 vec4::getScaled(const vec4 & rhs) const
{
	return { x * rhs.x, y * rhs.y, z * rhs.z, t * rhs.t };
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	vec4 temp(x + rhs.x, y + rhs.y, z + rhs.z, t + rhs.t);
	return temp;
}

vec4 vec4::operator-(const vec4 & rhs) const
{
	vec4 temp(x - rhs.x, y - rhs.y, z - rhs.z, t - rhs.t);
	return temp;
}

vec4 vec4::operator*(const float rhs) const
{
	return { x * rhs, y * rhs, z * rhs, t * rhs };
}

vec4 vec4::operator/(const float rhs) const
{
	return { x / rhs, y / rhs, z / rhs, t / rhs };
}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	t += rhs.t;
	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	t -= rhs.t;
	return *this;
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	return { rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.t * lhs };
}

vec4 & vec4::operator*=(const float rhs)
{
	return (*this = { x * rhs, y * rhs, z * rhs, t * rhs });
}

vec4 & vec4::operator/=(const float rhs)
{
	return (*this = { x / rhs, y / rhs, z / rhs, t / rhs });
}

bool vec4::operator==(const vec4 & rhs) const
{
	if ((x - rhs.x) < FLT_EPSILON && (y - rhs.y) < FLT_EPSILON &&
		(z - rhs.z) < FLT_EPSILON && (t - rhs.t) < FLT_EPSILON)
	{
		return true;
	}
	return false;
}

bool vec4::operator!=(const vec4 & rhs) const
{
	if ((x - rhs.x) < FLT_EPSILON && (y - rhs.y) < FLT_EPSILON &&
		(z - rhs.z) < FLT_EPSILON && (t - rhs.t) < FLT_EPSILON)
	{
		return false;
	}
	return true;
}

vec4 vec4::operator--() const
{
	vec4 temp(-x, -y, -z, -t);
	return temp; 
}

vec4::operator float*()
{

	return &x;
}

vec4::operator const float*() const
{
	return &x;
}
