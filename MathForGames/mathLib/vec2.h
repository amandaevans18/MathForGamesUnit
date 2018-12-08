#pragma once
#include "utils.h"
//anything w/out comments still needs to be completed
struct vec2
{
	float const THRESHOLD = .5;
	float x, y;

	vec2();
	vec2(float _x, float _y);

//
float magnitude() const;
//
float dot(const vec2 &rhs) const;

//
vec2 &normalize();
//
vec2 getNormalized() const;

//
vec2 &scale(const vec2 &rhs);
//
vec2 getScaled(const vec2 &rhs) const;

//
vec2 getPerpCW() const;
//
vec2 getPerpCCW() const;

//
float angleBetween(const vec2 &rhs) const;

//Operator to add a vec2 to another vec2 ,returns a vec2
vec2 operator+(const vec2 &rhs) const;

//Operator to subtract a vec2 from another vec2 ,returns a vec2
vec2 operator-(const vec2 &rhs) const;

//Operator plus equals shortcut that adds and sets a vec2 with another vec2 ,returns a vec2
vec2 &operator+=(const vec2 &rhs);
//Operator minus equals shortcut that subtracts and sets a vec2 with another vec2 ,returns a vec2
vec2 &operator-=(const vec2 &rhs);
//Operator multiplied equals shortcut that multiplies and sets a vec2 with another vec2 ,returns a vec2
vec2 &operator*=(const float rhs);
//Operator divided equals shortcut that divides and sets a vec2 with another vec2 ,returns a vec2
vec2 &operator/=(const float rhs);

//Operator used to compare a const float to another float (uses the THRESHOLD defined in vec2.lib) returns a bool
bool operator==(const float rhs) const;
//Operator used to compare a const float to another float (uses the THRESHOLD defined in vec2.lib) returns a bool
bool operator!=(const float rhs) const;

//Operator to help negatively iterate ,returns a vec2.  
vec2 operator--() const;

// Operator to access the value at that index
float &operator[](size_t idx);
// Operator to access a const value at that index
float operator[](size_t idx) const;

//returns the reference to the varible
operator const float *() const;

};

vec2 operator*(const float lhs, const vec2 &rhs);