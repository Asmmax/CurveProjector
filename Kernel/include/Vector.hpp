#pragma once
#include "ApproxDouble.hpp"
#include <cfloat>

class Point;

class Vector {
private:
	double _x;
	double _y;
	double _z;
	double _epsilon;
public:
	Vector(double x, double y, double z, double epsilon = DBL_EPSILON);
	Vector(const Point& start, const Point& end);

	inline const double& x() const { return _x; }
	inline const double& y() const { return _y; }
	inline const double& z() const { return _z; }
	inline const double& epsilon() const { return _epsilon; }

	ApproxDouble length() const;
	Vector normal() const;
	Vector& normalize();
	Vector projectTo(const Vector& dir) const;
	ApproxDouble dot(const Vector& other) const;
	Vector operator*(const ApproxDouble& right) const;
};