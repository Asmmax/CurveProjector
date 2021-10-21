#include "Polyline.hpp"
#include <assert.h>
#include <list>

Polyline::Polyline(const std::vector<Point>& points, double tolerance):
	_points(points),
	_tolerance(tolerance)
{
}

std::vector<Polyline::Projection> Polyline::project(const Point& point) const
{
	std::vector<Polyline::Projection> projections;

	std::vector<ApproxDouble> params;
	std::vector<Point> projectPoints;
	std::vector<ApproxDouble> distances;

	unsigned int segCount = segmentCount();
	params.reserve(segCount);
	projectPoints.reserve(segCount);
	distances.reserve(segCount);

	foreachSegment([point, &params, &projectPoints, &distances](const Segment& seg)
		{
			params.emplace_back(seg.project(point));
			projectPoints.emplace_back(seg.evaluate(params.back()));
			distances.emplace_back(point.distanceTo(projectPoints.back()));
		});

	std::list<unsigned int> extremums;
	extremums.emplace_back(0);

	for (int i = 1; i < distances.size(); i++) {
		if (ApproxDouble::less(distances[i], distances[extremums.front()], _tolerance)) {
			extremums.clear();
			extremums.emplace_back(i);
		}
		else if (ApproxDouble::equal(distances[i], distances[extremums.front()], _tolerance)){
			extremums.emplace_back(i);
		}
	}

	for (auto extremum : extremums) {
		projections.emplace_back(Polyline::Projection{ extremum, params[extremum], projectPoints[extremum] });
	}

	return projections;
}

Segment Polyline::getSegment(unsigned int segmentId) const
{
	return Segment(Point{ 0.0, 0.0, 0.0 }, Point{ 0.0, 0.0, 0.0 });
}

unsigned int Polyline::segmentCount() const
{
	unsigned int pointCount = _points.size();
	assert(pointCount >= 2);
	return pointCount - 1;
}

void Polyline::foreachSegment(std::function<void(const Segment&)> function) const
{
	for (int i = 0; i < segmentCount(); i++) {
		Segment currentSegment = getSegment(i);
		function(currentSegment);
	}
}
