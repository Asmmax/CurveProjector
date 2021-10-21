#pragma once
#include <cfloat>
#include <list>
#include <vector>

class ApproxDouble
{
private:
	double _value;
	double _epsilon;
public:
	ApproxDouble(double value, double epsilon = DBL_EPSILON);
	inline const double& value() const { return _value; }
	inline const double& epsilon() const { return _epsilon; }
	inline const double tolerance() const { return _epsilon * _value; }

	static bool equal(const ApproxDouble& left, const ApproxDouble& right, double tolerance);
	static bool less(const ApproxDouble& left, const ApproxDouble& right, double tolerance);
	static std::list<unsigned int> min(const std::vector<ApproxDouble>& values, double tolerance);
	ApproxDouble clamp(double min, double max) const;

	bool operator>(const double& right) const;
	bool operator<(const double& right) const;
	bool operator>(const ApproxDouble& right) const;
	bool operator<(const ApproxDouble& right) const;
	bool operator==(const ApproxDouble& right) const;

	ApproxDouble operator/(const ApproxDouble& other) const;
};
