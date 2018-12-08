#pragma once
#include"raylib.h"
#include<cmath>

/*
 Drawing a circle:
 - Identify the locations of all the points you'd like to draw on the circle.
 - Draw lines between each point on the circle connecting one after the other.
 * The smoothness of the circle depends on the arc between each point, the smoother it will appear.
 */

//Takes a float for radius an int for amount of points and a vector2(raylib) for position of center of circlef
class drawingACircle 
{
float static const OFF_SET_CHANGE;
struct myCirclePoint
{
	//that base center point (this bitch DO NOT CHANGE)
	Vector2 centerPos;
	//how far from the center that point is
	float radius;
	//difference between each point
	float offSet = 0;

	myCirclePoint(Vector2 _centerPos, float _radius, float _offset);
};
//
Vector2* allCirclePoints;

// loads enough points and stores them in a vector arr takes in time amount of points wanted in circle and a struct of myCirclePoint to make them
void pointLocation(float deltaTime, int amtOfPoints, myCirclePoint circle);

};