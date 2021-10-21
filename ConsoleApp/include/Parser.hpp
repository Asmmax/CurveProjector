#pragma once
#include <string>
#include "Point.hpp"
#include "Polyline.hpp"

class Parser {
public:
	static Point toPoint(const std::string& str);
	static Point toPoint(const std::string& xString, const std::string& yString, const std::string& zString);
	static std::string toString(const Point& point);

	static std::string toString(const std::vector<Polyline::Projection>& projections);
	static std::string toString(const Polyline::Projection& projection);
};
