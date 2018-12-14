#pragma once
#include"Lerping.h"

template<typename T>
 T BezierCurves<T>::quadraticBezier(const T & a, const T & b, const T & c, float t)
{
	T x = lerp(a, b, t);
	T y = lerp(b, c, t);

	return lerp(x,y,t);
}

 template<typename T>
 T BezierCurves<T>::quadraticSpline(const T & a, const T & b, const T & c, float t)
 {
	 T x = lerp(a, b, t);
	 T y = lerp(b, c, t);
	 T z = lerp(c, d, t);

	 return quadraticBezier(x, y, z, t);
 }

