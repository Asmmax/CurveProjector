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

	segmentDir.normalize();
	ApproxDouble paramProject = segmentDir.dot(toPoint);
	ApproxDouble paramMax = segmentDir.length();
	if (paramProject < 0) {
		return point.distanceTo(_start);
	}
	else if (paramProject > paramMax) {
		return point.distanceTo(_end);
	}
	else{
		Vector toIntersect = segmentDir * paramProject;
		Point intersectPoint = _start.move(toIntersect);
		return point.distanceTo(intersectPoint);
	}
}