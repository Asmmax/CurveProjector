#pragma once
#include "Point.hpp"
#include "ApproxDouble.hpp"

/**
 * Class defines a line segment in three dimensional space.
 */
class Segment {
private:
	Point _start;
	Point _end;
public:

	/**
	* Constructor for the Segment class.
	*
	* @param start Start point of required line segment.
	* @param end End point of required line segment.
	*/
	Segment(const Point& start, const Point& end);

	/*
	 * Project given point to current line segment.
	 *
	 * @param point Given point.
	 * @return approx param value that is relative to the line segment.
	 * 
	 * @remarks If the projection point lies beyond the line segment boundaries, the parameter is 0 or 1.
	 */
	ApproxDouble project(const Point& point) const;

	/*
	 * Calculates point on the line segment corresponding to the specified parameter.
	 *
	 * @param param Specified parameter.
	 * @return Corresponding point.
	 */
	Point evaluate(const ApproxDouble& param) const;

	/*
	 * Calculates minimum distance from given point to current line segment.
	 *
	 * @param point Given Point.
	 * @return approx value of distance between the point and the line segment.
	 */
	ApproxDouble distanceTo(const Point& point) const;
};
