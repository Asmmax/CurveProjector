#pragma once
#include "ApproxDouble.hpp"
#include <cfloat>

class Point;

/**
 * Class defines a vector in three dimensional space taking into account tolerance.
 */
class Vector {
private:
	double _x;
	double _y;
	double _z;
	double _epsilon;
public:

	/**
	 * Constructor for the Vector class.
	 *
	 * @param x Value on X-axis in space.
	 * @param y Value on Y-axis in space.
	 * @param z Value on Z-axis in space.
	 * @param epsilon Relative tolerance for the values. Default is around 2.2e-16.
	 */
	Vector(double x, double y, double z, double epsilon = DBL_EPSILON);

	/**
	 * Constructor for the Vector class.
	 *
	 * @param start Start point of required vector.
	 * @param end End point of required vector.
	 */
	Vector(const Point& start, const Point& end);

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
	 * Calculates length of current vector.
	 *
	 * @return Approx length of the vector.
	 */
	ApproxDouble length() const;

	/**
	 * Gives normal of vector.
	 *
	 * @return New normalized Vector.
	 */
	Vector normal() const;

	/**
	 * Normalize current vector.
	 *
	 * @return Refference to current normalized Vector.
	 */
	Vector& normalize();

	/**
	 * Project current vector to given one.
	 *
	 * @param dir Directional vector to which the current vector is projected.
	 * @return New projected vector.
	 */
	Vector projectTo(const Vector& dir) const;

	/**
	 * Calculates dot product between current and given vectors.
	 *
	 * @param other Given vector.
	 * @return approx value of the dot product.
	 */
	ApproxDouble dot(const Vector& other) const;

	/**
	 * Multiplies current approx point by given approx value.
	 *
	 * @param right Given value.
	 * @return New multiplied Vector object.
	 */
	Vector& operator*(const ApproxDouble& right);

	/**
	 * Divides current approx point by given approx value.
	 *
	 * @param right Given value.
	 * @return New divided Vector object.
	 */
	Vector& operator/(const ApproxDouble& right);
};
