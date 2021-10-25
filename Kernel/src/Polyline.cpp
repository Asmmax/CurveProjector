#include "Polyline.hpp"
#include <assert.h>

Polyline::Polyline(const std::vector<Point>& points, double tolerance):
	_points(points),
	_tolerance(tolerance)
{
	auto pointCount = static_cast<unsigned int>(_points.size());
	if (pointCount < 2)
		return;

	_segments.reserve(pointCount - 1);
	for (unsigned int i = 1; i < pointCount; i++) 
	{
		_segments.emplace_back(_points[i - 1], _points[i]);
	}
}

std::vector<Projection> Polyline::project(const Point& point) const
{
	Projector projector(_segments, _tolerance);
	return projector.project(point);
}

const Segment& Polyline::getSegment(unsigned int segmentId) const
{
	assert(_segments.size() > segmentId);

	return _segments[segmentId];
}

unsigned int Polyline::segmentCount() const
{
	return static_cast<unsigned int>(_segments.size());
}
