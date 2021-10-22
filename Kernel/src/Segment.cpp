#include "Segment.hpp"
#include "Vector.hpp"

Segment::Segment(const Point& start, const Point& end):
	_start(start),
	_end(end)
{
}

ApproxDouble Segment::project(const Point& point) const
{
	Vector segmentDir{ _start, _end };
	Vector toPoint{ _start, point };

	auto paramProject = segmentDir.normal().dot(toPoint) / segmentDir.length();
	return paramProject.clamp(0.0, 1.0);
}

Point Segment::evaluate(const ApproxDouble& param) const
{
	Vector segmentDir{ _start, _end };
	return _start.move(segmentDir * param);
}

ApproxDouble Segment::distanceTo(const Point& point) const
{
	auto paramProject = project(point);
	auto intersectPoint = evaluate(paramProject);
	return point.distanceTo(intersectPoint);
}
