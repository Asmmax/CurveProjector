#pragma once
#include "Point.hpp"
#include "Segment.hpp"
#include <vector>
#include <functional>

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

	std::vector<Projection> project(const Point& point) const;
	Segment getSegment(unsigned int segmentId) const;
	unsigned int segmentCount() const;
	void foreachSegment(std::function<void(const Segment&)> function) const;
};