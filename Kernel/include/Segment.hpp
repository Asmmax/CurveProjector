#pragma once
#include "Point.hpp"
#include "ApproxDouble.hpp"

class Segment {
private:
	Point _start;
	Point _end;
public:
	Segment(const Point& start, const Point& end);

	ApproxDouble project(const Point& point) const;
	Point evaluate(const ApproxDouble& param) const;
	ApproxDouble distanceTo(const Point& point) const;
};