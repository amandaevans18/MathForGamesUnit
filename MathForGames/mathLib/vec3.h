#pragma once
struct vec3
{
	float const THRESHOLD = .5;
	float x, y, z;

	vec3();
	vec3(float x, float y, float z);

	float magnitude() const;
	float dot(const vec3 &rhs) const;
	vec3 cross(const vec3 &rhs) const;

	vec3 &normalize();
	vec3 getNormalised();

	vec3 &scale(const vec3 &rhs);
	vec3 getScaled(const vec3 &rhs) const;

	//Operator to add a vec2 to another vec3 ,returns a vec3
	vec3 operator+(const vec3 &rhs) const;
	//add des
	vec3 operator-(const vec3 &rhs) const;
	//add des
	vec3 operator*(const float rhs) const;
	//add des
	friend vec3 operator*(const float lhs, const vec3 &rhs);
	//add des
	vec3 operator/(const float rhs) const;

	//add des
	vec3 &operator+=(const vec3 &rhs);
	//add des
	vec3 &operator-=(const vec3 &rhs);
	//add des
	vec3 &operator*=(const float rhs);
	//add des
	vec3 &operator/=(const float rhs);

	//
	bool operator==(const vec3 &rhs) const;
	//
	bool operator!=(const vec3 &rhs) const;

	vec3 operator--() const;


	operator const float *() const;
};

vec3 operator*(const float lhs, const vec3 &rhs);