#include "Parser.hpp"
#include <stdlib.h>

Point Parser::toPoint(const std::string& str)
{
	auto firstSpace = str.find(" ");
	std::string xString = str.substr(0, firstSpace);
	std::string residue = str.substr(firstSpace + 1);

	auto secondSpace = residue.find(" ");
	std::string yString = residue.substr(0, secondSpace);
	residue = residue.substr(secondSpace + 1);

	std::string zString = residue;

	return toPoint(xString, yString, zString);
}

Point Parser::toPoint(const std::string& xString, const std::string& yString, const std::string& zString)
{
	return Point{ atof(xString.c_str()), atof(yString.c_str()), atof(zString.c_str()) };
}

std::string Parser::toString(const Point& point)
{
	return std::to_string(point.x()) + " " + std::to_string(point.y()) + " " + std::to_string(point.z());
}

std::string Parser::toString(const std::vector<Polyline::Projection>& projections)
{
	std::string result;
	for (auto& projection : projections) {
		result += toString(projection);
		result += "\n";
	}
	return result;
}

std::string Parser::toString(const Polyline::Projection& projection)
{
	std::string result;

	result += "segment ";
	result += std::to_string(projection.segmentId);

	result += " parameter ";
	result += std::to_string(projection.param.value());

	result += " point ";
	result += toString(projection.point);

	return result;
}
