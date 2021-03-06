#include "Vector.h"



Vector::Vector()
	: x(0.0f), y(0.0f), z(0.0f)
{
}

Vector::Vector(float x, float y, float z)
	: x(x), y(y), z(z)
{
}

void Vector::Normalize()
{
	float lenght = GetLength();

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
	case Axis::X:
			x = -x;
			break;
	case Axis::Y:
			y = -y;
			break;
	case Axis::Z:
			z = -z;
			break;
	}
}

void Vector::Multiply(float multiplier)
{
	x *= multiplier;
	y *= multiplier;
	z *= multiplier;
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
