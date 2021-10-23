#include "Vector.hpp"
#include "Point.hpp"
#include <cmath>
#include <cfloat>

Vector::Vector(double x, double y, double z) :
	_x(x),
	_y(y),
	_z(z),
	_tolerance(maxValue()* DBL_EPSILON)
{
}

Vector::Vector(double x, double y, double z, double tolerance):
	_x(x),
	_y(y),
	_z(z),
	_tolerance(tolerance)
{
}

Vector::Vector(const Point& start, const Point& end):
	_x(end.x() - start.x()),
	_y(end.y() - start.y()),
	_z(end.z() - start.z()),
	_tolerance(start.tolerance() + end.tolerance())
{
}

ApproxDouble Vector::length() const
{
	double newValue = sqrt(_x * _x + _y * _y + _z * _z);
	double newTol = std::abs((_x + _y + _z) / newValue) * tolerance();
	return ApproxDouble(newValue, newTol);
}

Vector Vector::normal() const
{
	Vector copy(*this);
	copy.normalize();
	return copy;
}

Vector& Vector::normalize()
{
	return *this / length();
}

Vector Vector::projectTo(const Vector& dir) const 
{
	auto normalDir = dir.normal();
	return normalDir * (normalDir.dot(*this));
}

ApproxDouble Vector::dot(const Vector& other) const
{
	return ApproxDouble{ _x * other._x + _y * other._y + _z * other._z, std::abs(2 * (_x + _y + _z)) * tolerance() };
}

Vector& Vector::operator*(const ApproxDouble& right)
{
	double rightValue = right.value();
	_x *= rightValue;
	_y *= rightValue;
	_z *= rightValue;
	_tolerance = std::abs((maxValue() + rightValue)) * std::max({ right.tolerance(), tolerance() });
	return *this;
}

Vector& Vector::operator/(const ApproxDouble& right)
{
	double rightValue = right.value();
	_x /= rightValue;
	_y /= rightValue;
	_z /= rightValue;
	_tolerance = std::abs((maxValue() / rightValue + 1) / rightValue) * std::max({ right.tolerance(), tolerance() });
	return *this;
}
