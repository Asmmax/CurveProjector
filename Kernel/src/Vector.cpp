#include "Vector.hpp"
#include "Point.hpp"
#include <cmath>
#include <utility>

Vector::Vector(double x, double y, double z, double epsilon):
	_x(x),
	_y(y),
	_z(z),
	_epsilon(epsilon)
{
}

Vector::Vector(const Point& start, const Point& end):
	_x(end.x() - start.x()),
	_y(end.y() - start.y()),
	_z(end.z() - start.z()),
	_epsilon(std::max(start.epsilon(), end.epsilon()))
{
}

ApproxDouble Vector::length() const
{
	return ApproxDouble(sqrt(_x * _x + _y * _y + _z * _z), _epsilon);
}

Vector Vector::normal() const
{
	Vector copy(*this);
	copy.normalize();
	return copy;
}

Vector& Vector::normalize()
{
	ApproxDouble len = length();
	double lenValue = len.value();
	_x /= lenValue;
	_y /= lenValue;
	_z /= lenValue;
	_epsilon += len.epsilon();
	return *this;
}

Vector Vector::projectTo(const Vector& dir) const 
{
	Vector normalDir = dir.normal();
	return normalDir * (normalDir.dot(*this));
}

ApproxDouble Vector::dot(const Vector& other) const
{
	return ApproxDouble{ _x * other._x + _y * other._y + _z * other._z, _epsilon + other._epsilon };
}

Vector Vector::operator*(const ApproxDouble& right) const
{
	double rightValue = right.value();
	return Vector{ _x * rightValue , _y * rightValue , _z * rightValue, _epsilon + right.epsilon() };
}