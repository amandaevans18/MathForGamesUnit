#include "DrawingACircle.h"
#define OFF_SET_CHANGE = 1;

drawingACircle::myCirclePoint::myCirclePoint(Vector2 _centerPos, float _radius, float _offset)
{
	centerPos = _centerPos;
	radius = _radius;
	offSet = _offset;
}


void drawingACircle::pointLocation(float deltaTime, int amtOfPoints, myCirclePoint circle)
{
	Vector2 * circlePoints = new Vector2;
	Vector2 posOfPoint;
	for (int i = 0; i < amtOfPoints; i++)
	{

	}
}


