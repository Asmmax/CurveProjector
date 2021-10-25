#pragma once
#include "ApproxDouble.hpp"
#include "Point.hpp"
#include "Segment.hpp"

#include <vector>
#include <list>

/**
 * Struct defines a projection data such as segment number, projection param and point.
 */
struct Projection {
	unsigned int segmentId;
	ApproxDouble param;
	Point point;
};

/**
 * Class is responsible for the point projection to geometric primitives.
 */
class Projector
{
private:
	std::vector<ApproxDouble> _params;
	std::vector<Point> _projectPoints;
	std::vector<ApproxDouble> _distances;
	std::vector<Segment> _segments;
	double _tolerance;
public:

	/*
	* Constructor for the Projector class
	*
	* @param segments Set of segments that are approximation of curve.
	* @param tolerance Absolute tolerance of approximation.
	*/
	Projector(const std::vector<Segment>& segments, double tolerance);

	/*
	 * Calculate projection of given point to the curve.
	 *
	 * @param point Given point.
	 * @return Set of projection data that has segment number, projection param and point.
	 */
	std::vector<Projection> project(const Point& point);
private:

	/*
	 * Throws rays from a given point to each segment of the approximated curve.
	 *
	 * @param point Given point.
	 */
	void throwRaysToEachSegment(const Point& point);

	/*
	 * Selects only those rays that intersect with the nearest segments
	 *
	 * @param tolerance Absolute tolerance of segments.
	 * @return List of ray indices. Since the ray intersect points can coincide within the tolerance.
	 */
	std::list<unsigned int> selectNearestRays(double tolerance);
};