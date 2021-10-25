#include "Projector.hpp"
#include <algorithm>

Projector::Projector(const std::vector<Segment>& segments, double tolerance):
	_segments(segments),
	_tolerance(tolerance)
{
	auto segCount = _segments.size();
	_params.reserve(segCount);
	_projectPoints.reserve(segCount);
	_distances.reserve(segCount);
}

std::vector<Projection> Projector::project(const Point& point)
{
	throwRaysToEachSegment(point);
	auto nearestRays = selectNearestRays(_tolerance);

	std::vector<Projection> projections;
	for (auto ray : nearestRays) {
		projections.emplace_back(Projection{ ray, _params[ray], _projectPoints[ray] });
	}

	return projections;
}

void Projector::throwRaysToEachSegment(const Point& point)
{
	auto segCount = _segments.size();
	for (unsigned int i = 0; i < segCount; i++) {
		_params.emplace_back(_segments[i].project(point));
		_projectPoints.emplace_back(_segments[i].evaluate(_params.back()));
		_distances.emplace_back(point.distanceTo(_projectPoints.back()));
	}
}

std::list<unsigned int> Projector::selectNearestRays(double tolerance)
{
	auto extremums = ApproxDouble::min(_distances, _tolerance);

	//remove duplicate projections
	auto uniqueEnd = std::unique(extremums.begin(), extremums.end(), [this](auto first, auto second) {
		return _projectPoints[first] == _projectPoints[second];
		});
	extremums.erase(uniqueEnd, extremums.end());

	return extremums;
}