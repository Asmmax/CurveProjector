#pragma once
#include <string>
#include "Point.hpp"

class PointParser {
public:
	Point toPoint(const std::string& xString, const std::string& yString, const std::string& zString);
};
