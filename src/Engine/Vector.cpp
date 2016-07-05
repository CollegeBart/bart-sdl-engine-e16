#include "Vector.h"



Vector::Vector()
	: x(0.0f), y(0.0f), z(0.0f)
{
}

Vector::Vector(float x, float y, float z = 0.0f)
	: x(x), y(y), z(z)
{
}

Vector::Vector(Point p1, Point p2)
	: x(p2.x - p1.x), y(p2.y - p1.y), z(0.0f)
{
}

void Vector::Normalize(Vector * v)
{
	float lenght = GetLenght();

	v->x /= lenght;
	v->y /= lenght;
	v->z /= lenght;
}

float Vector::Dot(Vector * other)
{
	return x * other->x + y * other->y + z * other->z;
}

float Vector::GetLenght() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Vector::Reflect(Vector * v, int axis)
{
	switch (axis)
	{
		case 0:
			v->x = -v->x;
			break;
		case 1:
			v->y = -v->y;
			break;
		case 2:
			v->z = -v->z;
			break;
	}
}

void Vector::Multiply(float multiplyer)
{
	x *= multiplyer;
	y *= multiplyer;
	z *= multiplyer;
}

Vector & Vector::operator+(Vector & other)
{
	// TODO: insert return statement here
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}


Vector::~Vector()
{
}
