#pragma once
#include "ApproxDouble.hpp"
#include <cfloat>

class Vector;

class Point {
private:
	double _x;
	double _y;
	double _z;
	double _epsilon;
public:
	Point(double x, double y, double z, double epsilon = DBL_EPSILON);

	inline const double& x() const { return _x; }
	inline const double& y() const { return _y; }
	inline const double& z() const { return _z; }
	inline const double& epsilon() const { return _epsilon; }

	Point move(const Vector& dir) const;
	ApproxDouble distanceTo(const Point& target) const;
};