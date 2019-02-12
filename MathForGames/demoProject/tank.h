#pragma once
#include "transform.h"
#include "raylib.h"

class tank
{
public:
	Texture2D text;
	transform2d transform;
	Rectangle sourceRec;
	vec2 velocity;
	float width;
	float height;


	tank();
	tank(char * filename, float _width, float _height, Rectangle _sourceRec, vec2 _velocity, transform2d * _parent);
	void update(float deltaTime);
	void draw();
};