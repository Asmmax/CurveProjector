#pragma once
#include "ApproxDouble.hpp"
#include <cfloat>

class Vector;

/**
 * Class defines a point in three dimensional space taking into account tolerance.
 */
class Point {
private:
	double _x;
	double _y;
	double _z;
	double _epsilon;
public:

	/**
	 * Constructor for the Point class.
	 * 
	 * @param x Value on X-axis in space.
	 * @param y Value on Y-axis in space.
	 * @param z Value on Z-axis in space.
	 * @param epsilon Relative tolerance for the values. Default is around 2.2e-16.
	 */
	Point(double x, double y, double z, double epsilon = DBL_EPSILON);

	/**
	 * Gives current value on X-axis in space.
	 *
	 * @return Reference to the current X value.
	 */
	inline const double& x() const { return _x; }

	/**
	 * Gives current value on Y-axis in space.
	 *
	 * @return Reference to the current Y value.
	 */
	inline const double& y() const { return _y; }

	/**
	 * Gives current value on Z-axis in space.
	 *
	 * @return Reference to the current Z value.
	 */
	inline const double& z() const { return _z; }

	/**
	 * Gives relative tolerance.
	 *
	 * @return Reference to the current relative tolerance as double.
	 */
	inline const double& epsilon() const { return _epsilon; }

	/**
	 * Moves point by vector.
	 *
	 * @param dir Direction vector in which offset is performed.
	 * @return New moved Point object.
	 */
	Point move(const Vector& dir) const;

	/**
	* Calculates distance between current point and target point.
	*
	* @param target Target point.
	* @return approx value of distance between the points.
	*/
	ApproxDouble distanceTo(const Point& target) const;

	/**
	 * Checks if current point approx equal given point.
	 *
	 * @param right Given point.
	 * @return true if current point approx equal given point and flase otherwise.
	 */
	bool operator==(const Point& right) const;
};
