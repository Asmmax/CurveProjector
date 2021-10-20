#pragma once
#include <cfloat>

class ApproxDouble
{
private:
	double _value;
	double _epsilon;
public:
	ApproxDouble(double value, double epsilon = DBL_EPSILON);
	inline const double& value() const { return _value; }
	inline const double& epsilon() const { return _epsilon; }
};
