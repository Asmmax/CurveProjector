#pragma once
#include "Point.hpp"
#include "Segment.hpp"
#include <vector>

class Polyline {
public:
	struct Projection {
		unsigned int segmentId;
		ApproxDouble param;
	};
private:
	std::vector<Point> _points;
public:
	Polyline(const std::vector<Point>& points);

	std::vector<Projection> project(const Point& point);
	Segment getSegment(unsigned int segmentId);
};