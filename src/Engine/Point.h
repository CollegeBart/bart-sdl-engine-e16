#pragma once

#include <math.h>

template <class T>
struct Point
{
	Point() : x(0), y(0) {}
	Point(float x, float y) : x(x), y(y) {}

	static float GetLength(const Point& p)
	{
		return sqrt(pow(p.x, 2) + pow(p.y, 2));
	}

	static bool Normalize(Point& p)
	{
		int length = GetLength(p);
		if (length != 0)
		{
			p.x /= length;
			p.y /= length;
			return true;
		}
		return false;
	}

	T x, y;
};