#pragma once
#include "Point.h"
#include <math.h>

class Vector
{
public:
	enum Axis { X, Y, Z};

	Vector();
	Vector(float x, float y, float z = 0.0f);

	void Normalize();
	float Dot(Vector* other);
	float GetLength() const;

	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetZ() const { return z; }

	/**
	* Reflects a vector on the given axis :
	* 0: X
	* 1: Y
	* 2: Z
	*/
	void Reflect(Axis axis);

	void Multiply(float multiplier);

	Vector& operator+(Vector& other);

	~Vector();
private :
	float x;
	float y;
	float z;
};

