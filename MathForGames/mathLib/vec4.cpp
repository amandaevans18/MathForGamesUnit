#include "vec4.h"

vec4::vec4()
{
}

vec4::vec4(float x, float y, float z, float w)
{
}

float vec4::magnitude() const
{
	return 0.0f;
}

float vec4::dot(const vec4 & rhs) const
{
	return 0.0f;
}

vec4 vec4::cross(const vec4 & rhs) const
{
	return vec4();
}

vec4 & vec4::normalize()
{
	// TODO: insert return statement here
}

vec4 vec4::getNormalised()
{
	return vec4();
}

vec4 & vec4::scale(const vec4 & rhs)
{
	// TODO: insert return statement here
}

vec4 vec4::getScaled(const vec4 & rhs) const
{
	return vec4();
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	return vec4();
}

vec4 vec4::operator-(const vec4 & rhs) const
{
	return vec4();
}

vec4 vec4::operator*(const float rhs) const
{
	return vec4();
}

vec4 vec4::operator/(const float rhs) const
{
	return vec4();
}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	// TODO: insert return statement here
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	// TODO: insert return statement here
}

vec4 operator*(const float lhs, const vec4 & rhs)
{
	return vec4();
}

vec4 & vec4::operator*=(const float rhs)
{
	// TODO: insert return statement here
}

vec4 & vec4::operator/=(const float rhs)
{
	// TODO: insert return statement here
}

bool vec4::operator==(const vec4 & rhs) const
{
	return false;
}

bool vec4::operator!=(const vec4 & rhs) const
{
	return false;
}

vec4 vec4::operator--() const
{
	return vec4();
}

vec4::operator float*()
{
}

vec4::operator const float*() const
{
}
