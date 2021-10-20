#include "catch.hpp"
#include <cmath>

#include "Point.hpp"
#include "ApproxDouble.hpp"
#include "Segment.hpp"

TEST_CASE("Distance between point and segment", "[Segment]") {
	Point somePoint{ 5.0, 2.0, 1.0 };
	Segment someSegment{ Point{6.0, 2.0, 1.0}, Point{5.0, 3.0, 1.0} };
	
	ApproxDouble distance = someSegment.distanceTo(somePoint);
	REQUIRE(distance.epsilon() < 1e-10);
	REQUIRE(Approx(distance.value()).epsilon(distance.epsilon()) == sqrt(2.0) / 2.0);

	SECTION("Case of point with the projection beyond the start segment boundary") {
		Point somePoint{ 6.0, 0.0, 1.0 };
		Segment someSegment{ Point{6.0, 2.0, 1.0}, Point{5.0, 3.0, 1.0} };

		ApproxDouble distance = someSegment.distanceTo(somePoint);
		REQUIRE(distance.epsilon() < 1e-10);
		REQUIRE(Approx(distance.value()).epsilon(distance.epsilon()) == 2.0);
	}

	SECTION("Case of point with the projection beyond the end segment boundary") {
		Point somePoint{ 0.0, 3.0, 1.0 };
		Segment someSegment{ Point{6.0, 2.0, 1.0}, Point{5.0, 3.0, 1.0} };

		ApproxDouble distance = someSegment.distanceTo(somePoint);
		REQUIRE(distance.epsilon() < 1e-10);
		REQUIRE(Approx(distance.value()).epsilon(distance.epsilon()) == 5.0);
	}
}

TEST_CASE("Point to segment projection", "[Segment]") {
	Point somePoint{ 5.0, 2.0, 1.0 };
	Segment someSegment{ Point{6.0, 2.0, 1.0}, Point{5.0, 3.0, 1.0} };

	ApproxDouble param = someSegment.project(somePoint);
	Point projectPoint = someSegment.evaluate(param);

	Point requirePoint{ 5.5 , 2.5, 1.0 };
	REQUIRE(projectPoint.epsilon() < 1e-10);
	REQUIRE(projectPoint == requirePoint);
}
