#define _USE_MATH_DEFINES

#include "tank.h"
#include <cmath>

tank::tank()
{
	sourceRec = { 0, 0, 38, 36 };
	width = 38.0f;
	height = 36.0f;
	text = LoadTexture("Resources/tankBody_darl_outline.png");
	velocity = { 0, 0 };
	transform.localPos = { 400.0f, 225.0f };
	transform.localScale = { 1, 1 };
	transform.localRot = (3 * M_PI) / 2;
}

tank::tank(char * filename, float _width, float _height, Rectangle _sourceRec, vec2 _velocity, transform2d * _parent)
{
	sourceRec = _sourceRec;
	width = _width;
	height = _height;
	text = LoadTexture(filename);
	velocity = _velocity;
	transform.setParent(_parent);
	transform.localPos = { 400.0f, 225.0f };
}

void tank::update(float deltaTime)
{
	if (IsKeyDown(KEY_W))
	{
		velocity = (transform.forward() * 200 * deltaTime);
	}
	else if (IsKeyDown(KEY_S))
	{
		velocity = -(transform.forward() * 200 * deltaTime);
	}
	else
	{
		velocity = { 0, 0 };
	}

	if (IsKeyDown(KEY_D))
	{
		transform.rotate(5 * deltaTime);
	}
	else if (IsKeyDown(KEY_A))
	{
		transform.rotate(-5 * deltaTime);
	}

	transform.localPos += velocity;
}

void tank::draw()
{
	DrawTexturePro(text, { 0, 0, 38, 36 }, { transform.localPos.x, transform.localPos.y, 38 * transform.localScale.x, 36 * transform.localScale.y }, { 19, 18 }, transform.localRot * (180 / M_PI) + 90, WHITE);
}