#define _USE_MATH_DEFINES

#include "turret.h"
#include <cmath>

turret::turret(transform2d * _parent)
{
	sourceRec = { 0, 0, 12, 30 };
	width = 12.0f;
	height = 30.0f;
	text = LoadTexture("Resources/Using/tankDark_barrel3_outline.png");
	transform.localPos = { 0, 0 };
	transform.setParent(_parent);
	transform.localScale = { 1, 1 };
	transform.localRot = PI / 2;
}

turret::turret(char * filename, float _width, float _height, Rectangle _sourceRec, transform2d * _parent)
{
	sourceRec = _sourceRec;
	width = _width;
	height = _height;
	text = LoadTexture(filename);
	transform.setParent(_parent);
}

void turret::update(float deltaTime)
{
	if (IsKeyDown(KEY_RIGHT))
	{
		transform.rotate(5 * deltaTime);
	}
	else if (IsKeyDown(KEY_LEFT))
	{
		transform.rotate(-5 * deltaTime);
	}
}

void turret::draw()
{
	DrawTexturePro(text, sourceRec, { transform.worldPosition().x, transform.worldPosition().y, 12 * transform.localScale.x, 30 * transform.localScale.x }, { 6, 25 }, transform.worldRotation() * (180 / M_PI), WHITE);
}