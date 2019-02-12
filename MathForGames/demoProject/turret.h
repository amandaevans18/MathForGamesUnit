#pragma once
#include "transforms.h"
#include "raylib.h"

class turret
{
public:
	Texture2D text;
	transform2d transform;
	Rectangle sourceRec;
	float width;
	float height;

	turret() {}
	turret(transform2d * _parent);
	turret(char * filename, float _width, float _height, Rectangle _sourceRec, transform2d * _parent);
	void update(float deltaTime);
	void draw();
};