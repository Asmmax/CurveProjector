#include "ProjectionParser.hpp"
#include "PointParser.hpp"

ProjectionParser::ProjectionParser(PointParser* pointParser):
	_pointParser(pointParser)
{
}

std::string ProjectionParser::toString(const std::vector<Polyline::Projection>& projections)
{
	return std::string();
}
