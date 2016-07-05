#include "Vector.h"



Vector::Vector()
	: x(0.0f), y(0.0f), z(0.0f)
{
}

Vector::Vector(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

Vector::Vector(Point p1, Point p2)
	: x(p2.x - p1.x), y(p2.y - p1.y), z(0.0f)
{
}

void Vector::Normalize()
{
	float lenght = GetLenght();

	x /= lenght;
	y /= lenght;
	z /= lenght;
}

float Vector::Dot(Vector * other)
{
	return x * other->x + y * other->y + z * other->z;
}

float Vector::GetLength() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Vector::Reflect(Axis axis)
{
	switch (axis)
	{
		case 0:
			x = -x;
			break;
		case 1:
			y = -y;
			break;
		case 2:
			z = -z;
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
