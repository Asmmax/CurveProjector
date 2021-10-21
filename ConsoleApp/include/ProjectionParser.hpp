#pragma once
#include <string>
#include "Polyline.hpp"

class PointParser;

class ProjectionParser {
private:
	PointParser* _pointParser;
public:
	ProjectionParser(PointParser* pointParser);
	std::string toString(const std::vector<Polyline::Projection>& projections);
	std::string toString(const Polyline::Projection& projection);
};
