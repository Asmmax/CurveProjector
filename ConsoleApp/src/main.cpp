#include "Polyline.hpp"
#include "Point.hpp"
#include "Context.hpp"
#include "PolylineGateway.hpp"
#include "Parser.hpp"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
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

	Context context;
	PolylineGateway* polylineFab = context.polylineGateway();

	std::shared_ptr<Polyline> polyline = polylineFab->getPolyline(argv[1]);
	Point point = Parser::toPoint(argv[2], argv[3], argv[4]);

	std::vector<Polyline::Projection> projections = polyline->project(point);

	std::string projString = Parser::toString(projections);

	std::cout << "Projection has: " << projections.size() << " points" << std::endl;
	std::cout << projString;

	return 0;
}
