#include "Polyline.hpp"
#include <assert.h>

Polyline::Polyline(const std::vector<Point>& points, double tolerance):
	_points(points),
	_tolerance(tolerance)
{
}

std::vector<Polyline::Projection> Polyline::project(const Point& point) const
{
	std::vector<ApproxDouble> params;
	std::vector<Point> projectPoints;
	std::vector<ApproxDouble> distances;

	auto segCount = segmentCount();
	params.reserve(segCount);
	projectPoints.reserve(segCount);
	distances.reserve(segCount);

	foreachSegment([point, &params, &projectPoints, &distances](const Segment& seg)
		{
			params.emplace_back(seg.project(point));
			projectPoints.emplace_back(seg.evaluate(params.back()));
			distances.emplace_back(point.distanceTo(projectPoints.back()));
		});

	auto extremums = ApproxDouble::min(distances, _tolerance);

	std::vector<Polyline::Projection> projections;
	for (auto extremum : extremums) {
		projections.emplace_back(Polyline::Projection{ extremum, params[extremum], projectPoints[extremum] });
	}

	return projections;
}

Segment Polyline::getSegment(unsigned int segmentId) const
{
	assert(_points.size() >= 2);

	return Segment{ _points[segmentId], _points[segmentId + 1] };
}

unsigned int Polyline::segmentCount() const
{
	auto pointCount = static_cast<unsigned int>(_points.size());
	assert(pointCount >= 2);
	return pointCount - 1;
}

void Polyline::foreachSegment(std::function<void(const Segment&)> function) const
{
	for (unsigned int i = 0; i < segmentCount(); i++) {
		auto currentSegment = getSegment(i);
		function(currentSegment);
	}
}
