#include<iostream>
#include"vec2.h"
#include"Asserting.h"
int main() 
{
	
	// vector addition
	vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;


	TEST("Vector2 addition", v2c, vec2(18.5f, -44.24f));
	
	// vector subtraction
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	v2c = v2a - v2b;

	TEST("Vector2 subtraction", v2c, vec2(8.5f, -52.22f));
	
	// vector post-scale
	v2a = vec2(13.5f, -48.23f);
	v2c =  2.482f * v2a;

	TEST("Vector2 post-scale", v2c, vec2(33.5069999695f, -119.706863403f));
	
	// vector pre-scale
	v2a = vec2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	
	TEST("Vector2 pre-scale", v2c, vec2(33.5069999695f, -119.706863403f));

	// vector dot product
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	
	TEST("Vector2 dot", dot2, -124.937698364f);


	// vector magnitude
	v2a = vec2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();

	TEST("Vector2 magnitude", mag2, 50.0837593079f);
	
	// vector normalize
	v2a = vec2(-13.5f, -48.23f);
	v2a.normalize();

	TEST("Vector2 normalize", v2a, vec2(-0.269548f, -0.962987f));
	
	
	return 0;

}