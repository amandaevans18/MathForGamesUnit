#pragma once
template <typename T>
T lerp(const T& a, const T& b, float t)
{
	return a * (1 - t) + b * t;
}


// implementation two
template <typename T>
T lerpTwo(const T& a, const T& b, float t)
{
	return a + (b - a) * t;
}

template <typename T>
T linearEase(float t, const T& b, const T& c, float d)
{
	return b + c * (t / d);
}

template <typename T>
T easeInSine(float t, const T& b, const T& c, float d)
{
	return b + c - c * cosf(t / d * HALF_PI);
}