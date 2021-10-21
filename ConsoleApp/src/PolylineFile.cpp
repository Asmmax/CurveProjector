#include "PolylineFile.hpp"
#include "Polyline.hpp"
#include "PointParser.hpp"
#include <iostream>
#include <fstream>
#include <string>

PolylineFile::PolylineFile(PointParser* pointParser):
	_pointParser(pointParser)
{
}

std::shared_ptr<Polyline> PolylineFile::getPolyline(const std::string& name)
{
	std::vector<Point> points;

	std::ifstream polylineFile;
	polylineFile.open(name);

	if (polylineFile.is_open())
	{
		std::string line;
		
		while (std::getline(polylineFile, line))
		{
			points.emplace_back(_pointParser->toPoint(line));
		}
		polylineFile.close();
	}

	return std::make_shared<Polyline>(points);
}
