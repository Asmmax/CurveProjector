#include "Point.hpp"
#include "Vector.hpp"
#include <cfloat>

Point::Point(double x, double y, double z) :
	_x(x),
	_y(y),
	_z(z),
	_tolerance(maxValue()* DBL_EPSILON)
{
}

Point::Point(double x, double y, double z, double tolerance):
	_x(x),
	_y(y),
	_z(z),
	_tolerance(tolerance)
{
}

Point Point::move(const Vector& dir) const
{
	return Point{_x+dir.x(), _y+dir.y(), _z+dir.z(), _tolerance + dir.tolerance() };
}

ApproxDouble Point::distanceTo(const Point& target) const
{
	Vector height{ *this, target };
	return height.length();
}

bool Point::operator==(const Point& right) const
{
	return ApproxDouble{_x, _tolerance} == ApproxDouble{ right._x, right._tolerance } &&
		ApproxDouble{ _y, _tolerance } == ApproxDouble{ right._y, right._tolerance } &&
		ApproxDouble{ _z, _tolerance } == ApproxDouble{ right._z, right._tolerance };
}
