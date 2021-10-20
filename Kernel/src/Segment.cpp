#include "Segment.hpp"

Segment::Segment(const Point& start, const Point& end):
	_start(start),
	_end(end)
{
}

ApproxDouble Segment::distanceTo(const Point& point) const 
{
	return ApproxDouble{ 0.0, 0.0 };
}