#include "Point.hpp"
#include "Vector.hpp"
#include <utility>

Point::Point(double x, double y, double z, double epsilon):
	_x(x),
	_y(y),
	_z(z),
	_epsilon(epsilon)
{
}

Point Point::move(const Vector& dir) const
{
	return Point{_x+dir.x(), _y+dir.y(), _z+dir.z(), std::max(_epsilon, dir.epsilon())};
}

ApproxDouble Point::distanceTo(const Point& target) const
{
	Vector height{ *this, target };
	return height.length();
}

bool Point::operator==(const Point& other) const
{
	return ApproxDouble{_x, _epsilon} == ApproxDouble{ other._x, other._epsilon } &&
		ApproxDouble{ _y, _epsilon } == ApproxDouble{ other._y, other._epsilon } &&
		ApproxDouble{ _z, _epsilon } == ApproxDouble{ other._z, other._epsilon };
}
