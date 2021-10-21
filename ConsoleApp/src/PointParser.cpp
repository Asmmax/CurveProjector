#include "PointParser.hpp"
#include "Point.hpp"
#include <stdlib.h>

Point PointParser::toPoint(const std::string& str)
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

Point PointParser::toPoint(const std::string& xString, const std::string& yString, const std::string& zString)
{
	return Point{ atof(xString.c_str()), atof(yString.c_str()), atof(zString.c_str()) };
}

std::string PointParser::toString(const Point& point)
{
	return std::to_string(point.x()) + " " + std::to_string(point.y()) + " " + std::to_string(point.z());
}
