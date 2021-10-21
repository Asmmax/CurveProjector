#pragma once
#include "Point.hpp"
#include "Segment.hpp"
#include <vector>
#include <list>
#include <functional>

class Polyline {
public:
	struct Projection {
		unsigned int segmentId;
		ApproxDouble param;
		Point point;
	};
private:
	std::vector<Point> _points;
	double _tolerance;
public:
	Polyline(const std::vector<Point>& points, double tolerance = 0.0);

	std::vector<Projection> project(const Point& point) const;
	Segment getSegment(unsigned int segmentId) const;
	unsigned int segmentCount() const;
	void foreachSegment(std::function<void(const Segment&)> function) const;
};
