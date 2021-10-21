#include "catch.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "Polyline.hpp"
#include <vector>

TEST_CASE("Point to polyline projection", "[Polyline]") {
	std::vector<Point> points;
	points.emplace_back(0.0, 0.0, 0.0);
	points.emplace_back(0.0, 1.0, 0.0);
	points.emplace_back(3.0, 1.0, 3.0);

	Polyline somePolyline{ points };
	Point somePoint{ 2.0, 0.0, 2.0 };

	std::vector<Polyline::Projection> projections = somePolyline.project(somePoint);
	REQUIRE(projections.size() == 1);

	Polyline::Projection& projection = projections[0];
	Segment segment = somePolyline.getSegment(projection.segmentId);
	Point projectPoint = segment.evaluate(projection.param);
	REQUIRE(projection.point == projectPoint);

	Point requirePoint{ 2.0 , 1.0, 2.0 };
	REQUIRE(projection.point.epsilon() < 1e-10);
	REQUIRE(projection.point == requirePoint);

	SECTION("Case of many point projections")
	{
		std::vector<Point> points;
		points.emplace_back(2.0, 0.0, 0.0);
		points.emplace_back(2.0, 2.0, 0.0);
		points.emplace_back(0.0, 2.0, 0.0);

		Polyline somePolyline{ points };
		Point somePoint{ 1.0, 1.0, 0.0 };

		std::vector<Polyline::Projection> projections = somePolyline.project(somePoint);
		REQUIRE(projections.size() == 2);

		Point requirePoint1{ 2.0 , 1.0, 0.0 };
		REQUIRE(projections[0].point.epsilon() < 1e-10);
		REQUIRE(projections[0].point == requirePoint1);

		Point requirePoint2{ 1.0 , 2.0, 0.0 };
		REQUIRE(projections[1].point.epsilon() < 1e-10);
		REQUIRE(projections[1].point == requirePoint2);

	}
}
