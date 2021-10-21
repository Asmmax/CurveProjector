#include "Polyline.hpp"

Polyline::Polyline(const std::vector<Point>& points):
	_points(points)
{
}

std::vector<Polyline::Projection> Polyline::project(const Point& point)
{
	return std::vector<Polyline::Projection>();
}

Segment Polyline::getSegment(unsigned int segmentId)
{
	return Segment(Point{ 0.0, 0.0, 0.0 }, Point{ 0.0, 0.0, 0.0 });
}