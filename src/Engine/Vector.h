#pragma once
#include "Point.h"
#include <math.h>

class Vector
{
public:
	Vector();
	Vector(float x, float y, float z = 0.0f);
	Vector(Point p1, Point p2);

	void Normalize(Vector* v);
	float Dot(Vector* other);
	float GetLenght() const;


	/**
	* Reflects a vector on the given axis :
	* 0: X
	* 1: Y
	* 2: Z
	*/
	void Reflect(Vector * v, int axis);

	void Multiply(float multiplyer);

	Vector& operator+(Vector& other);

	~Vector();
private :
	float x;
	float y;
	float z;
};

