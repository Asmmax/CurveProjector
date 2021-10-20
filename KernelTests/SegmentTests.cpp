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
}