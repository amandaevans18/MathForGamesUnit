#pragma once
#include"vec2.h"
#include"mat3.h"

struct transform2d
{
	mat3 tranStorage;

	transform2d();

	vec2 localPos;
	float localRot;
	vec2 localScale;

	void translate(const vec2 &offset);
	void rotate(const float angle);

	void lookAt(const transform2d &target);
	vec2 forward() const;
	void setForward(const vec2 &newFwd);

	mat3 getTRSMatrix() const;
};