#include "PointParser.hpp"
#include "Point.hpp"
#include <stdlib.h>

Point PointParser::toPoint(const std::string& xString, const std::string& yString, const std::string& zString)
{
	return Point{ atof(xString.c_str()), atof(yString.c_str()), atof(zString.c_str()) };
}

std::string PointParser::toString(const Point& point)
{
	return std::to_string(point.x()) + " " + std::to_string(point.y()) + " " + std::to_string(point.z());
}
