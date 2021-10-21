#include "catch.hpp"
#include "Point.hpp"
#include "Segment.hpp"
#include "Polyline.hpp"
#include <vector>

TEST_CASE("Requirements for Kernel from the technical task", "[Requirements]") {

	SECTION("first sample")
	{
		std::vector<Point> points;
		points.emplace_back(0.0, 0.0, 0.0);
		points.emplace_back(1.0, 0.0, 0.0);
		points.emplace_back(2.0, 1.0, 0.0);
		points.emplace_back(3.0, 1.0, 1.0);

		Polyline somePolyline{ points, 1e-7 };
		Point somePoint{ 2.0, 0.5, 0.5 };

		std::vector<Polyline::Projection> projections = somePolyline.project(somePoint);
		REQUIRE(projections.size() == 2);

		REQUIRE(projections[0].segmentId == 1);
		REQUIRE(projections[0].param == 0.75);
		REQUIRE(projections[0].point == Point{ 1.75, 0.75 , 0.0 });

		REQUIRE(projections[1].segmentId == 2);
		REQUIRE(projections[1].param == 0.25);
		REQUIRE(projections[1].point == Point{ 2.25, 1.0 , 0.25 });
	}

	SECTION("second sample")
	{
		std::vector<Point> points;
		points.emplace_back(0.0, 0.0, 0.0);
		points.emplace_back(2.0, 0.0, 0.0);
		points.emplace_back(2.0, 2.0, 0.0);
		points.emplace_back(0.0, 2.0, 0.0);
		points.emplace_back(0.0, 0.0, 0.0);

		Polyline somePolyline{ points, 1e-7 };
		Point somePoint{ 1.0, 1.0, 1.0 };

		std::vector<Polyline::Projection> projections = somePolyline.project(somePoint);
		REQUIRE(projections.size() == 4);

		REQUIRE(projections[0].segmentId == 0);
		REQUIRE(projections[0].param == 0.5);
		REQUIRE(projections[0].point == Point{ 1.0, 0.0 , 0.0 });

		REQUIRE(projections[1].segmentId == 1);
		REQUIRE(projections[1].param == 0.5);
		REQUIRE(projections[1].point == Point{ 2.0, 1.0 , 0.0 });

		REQUIRE(projections[2].segmentId == 2);
		REQUIRE(projections[2].param == 0.5);
		REQUIRE(projections[2].point == Point{ 1.0, 2.0 , 0.0 });

		REQUIRE(projections[3].segmentId == 3);
		REQUIRE(projections[3].param == 0.5);
		REQUIRE(projections[3].point == Point{ 0.0, 1.0 , 0.0 });
	}

	SECTION("third sample")
	{
		std::vector<Point> points;
		points.emplace_back(0.0, 0.0, 0.0);
		points.emplace_back(2.0, 0.0, 0.0);
		points.emplace_back(2.0, 2.0, 0.0);
		points.emplace_back(0.0, 2.0, 0.0);
		points.emplace_back(0.0, 0.0, 0.0);

		Polyline somePolyline{ points, 1e-7 };
		Point somePoint{ 3.0, 3.0, 3.0 };

		std::vector<Polyline::Projection> projections = somePolyline.project(somePoint);
		REQUIRE(projections.size() == 2);

		REQUIRE(projections[0].segmentId == 1);
		REQUIRE(projections[0].param == 1.0);
		REQUIRE(projections[0].point == Point{ 2.0, 2.0 , 0.0 });

		REQUIRE(projections[1].segmentId == 2);
		REQUIRE(projections[1].param == 0.0);
		REQUIRE(projections[1].point == Point{ 2.0, 2.0 , 0.0 });
	}
}