#include "Polyline.hpp"
#include "Point.hpp"
#include "Context.hpp"
#include "PolylineGateway.hpp"
#include "PointParser.hpp"
#include "ProjectionParser.hpp"
#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 5) {
		std::cout << "Error input!" << std::endl;
		return 1;
	}

	Context context;
	PolylineGateway* polylineFab = context.polylineGateway();
	PointParser* pointParser = context.pointParser();
	ProjectionParser* projectionParser = context.projectionParser();

	std::shared_ptr<Polyline> polyline = polylineFab->getPolyline(argv[1]);
	Point point = pointParser->toPoint(argv[2], argv[3], argv[4]);

	std::vector<Polyline::Projection> projections = polyline->project(point);

	std::string projString = projectionParser->toString(projections);

	std::cout << "Projection has: " << projections.size() << " points" << std::endl;
	std::cout << projString;

	return 0;
}
