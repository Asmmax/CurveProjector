#pragma once
#include "Point.hpp"
#include "Segment.hpp"
#include <vector>
#include <list>
#include <functional>

/**
 * Class defines a polyline in three dimensional space.
 */
class Polyline {
public:
	/**
	 * Struct defines a projection data such as segment number, projection param and point.
	 */
	struct Projection {
		unsigned int segmentId;
		ApproxDouble param;
		Point point;
	};
private:
	std::vector<Point> _points;
	double _tolerance;
public:
	/*
	 * Constructor for the Polyline class
	 *
	 * @param points Set of points that are the vertices of a polyline.
	 * @param tolerance Absolute tolerance. Default is 0 and tolerance defines by points.
	 */
	Polyline(const std::vector<Point>& points, double tolerance = 0.0);

	/*
	 * Project given point to current polyline.
	 *
	 * @param point Given point.
	 * @return Set of projection data that has segment number, projection param and point.
	 */
	std::vector<Projection> project(const Point& point) const;

	/*
	 * Returns segment by segment number.
	 *
	 * @param segmentId Sequence number of the segment.
	 */
	Segment getSegment(unsigned int segmentId) const;

	/*
	 * Returns segment count in current polyline.
	 */
	unsigned int segmentCount() const;

	/*
	 * Applies the given function to each segment in the polyline.
	 * 
	 * @param function Given function.
	 */
	void foreachSegment(std::function<void(const Segment&)> function) const;
};
