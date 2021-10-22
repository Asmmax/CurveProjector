#include "ConsoleApp.hpp"
#include "PolylineGateway.hpp"
#include "Polyline.hpp"
#include "Point.hpp"
#include "Parser.hpp"
#include <string>
#include <iostream>

ConsoleApp::ConsoleApp(PolylineGateway& polylineGateway) :
	_polylineGateway(polylineGateway)
{
}

int ConsoleApp::run(int argc, char* argv[])
{
	if (argc < 5) {
		std::cout << "Error input!" << std::endl;
		std::cout << "You need to input 4 arguments" << std::endl;
		std::cout << "[file] [x] [y] [z]" << std::endl;
		std::cout << "file - text file with polyline points" << std::endl;
		std::cout << "x,y,z - values of three dimensional point" << std::endl;
		std::cout << "Example: \"file.txt\" 0 1 2.5" << std::endl;
		return 1;
	}

	auto polyline = _polylineGateway.getPolyline(argv[1]);
	auto point = Parser::toPoint(argv[2], argv[3], argv[4]);

	auto projections = polyline->project(point);

	std::cout << "Projection has: " << projections.size() << " points" << std::endl;
	std::cout << Parser::toString(projections);

	return 0;
}
