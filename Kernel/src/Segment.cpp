#include "Segment.hpp"
#include "Vector.hpp"

Segment::Segment(const Point& start, const Point& end):
	_start(start),
	_end(end)
{
}

ApproxDouble Segment::distanceTo(const Point& point) const 
{
	Vector segmentDir{ _start, _end };
	Vector toPoint{ _start, point };
	Vector toIntersect = toPoint.projectTo(segmentDir);
	Point intersectPoint = _start.move(toIntersect);

	return point.distanceTo(intersectPoint);
}