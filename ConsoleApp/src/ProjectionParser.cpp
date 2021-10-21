#include "ProjectionParser.hpp"
#include "PointParser.hpp"

ProjectionParser::ProjectionParser(PointParser* pointParser):
	_pointParser(pointParser)
{
}

std::string ProjectionParser::toString(const std::vector<Polyline::Projection>& projections) const
{
	std::string result;
	for (auto& projection : projections) {
		result += toString(projection);
		result += "\n";
	}
	return result;
}

std::string ProjectionParser::toString(const Polyline::Projection& projection) const
{
	std::string result;

	result += "segment ";
	result += std::to_string(projection.segmentId);

	result += " parameter ";
	result += std::to_string(projection.param.value());

	result += " point ";
	result += _pointParser->toString(projection.point);

	return result;
}
