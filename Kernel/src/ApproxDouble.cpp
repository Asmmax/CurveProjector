#include "ApproxDouble.hpp"
#include <utility>
#include <cfloat>
#include <cmath>

ApproxDouble::ApproxDouble(double value) :
	_value(value),
	_tolerance(value* DBL_EPSILON)
{
}


ApproxDouble::ApproxDouble(double value, double tolerance) :
	_value(value),
	_tolerance (tolerance)
{
}

bool ApproxDouble::equal(const ApproxDouble& left, const ApproxDouble& right, double tolerance)
{
	double sumTolerance = std::max(tolerance, left.tolerance()+ right.tolerance());
	return (left._value - sumTolerance) < right._value &&
		(left._value + sumTolerance) > right._value;
}

bool ApproxDouble::less(const ApproxDouble& left, const ApproxDouble& right, double tolerance)
{
	double sumTolerance = std::max(tolerance, left.tolerance() + right.tolerance());
	return (left._value + sumTolerance) < right._value;
}

std::list<unsigned int> ApproxDouble::min(const std::vector<ApproxDouble>& values, double tolerance)
{
	std::list<unsigned int> extremums;
	extremums.emplace_back(0);

	auto valueCount = static_cast<unsigned int>(values.size());
	for (unsigned int i = 1; i < valueCount; i++) {
		if (ApproxDouble::less(values[i], values[extremums.front()], tolerance)) {
			extremums.clear();
			extremums.emplace_back(i);
		}
		else if (ApproxDouble::equal(values[i], values[extremums.front()], tolerance)) {
			extremums.emplace_back(i);
		}
	}

	return extremums;
}

ApproxDouble ApproxDouble::clamp(double min, double max) const
{
	if (*this < min) {
		return ApproxDouble(min);
	}
	else if (*this > max) {
		return ApproxDouble(max);
	}
	return *this;
}

bool ApproxDouble::operator>(const double& right) const
{
	return _value - tolerance() > right;
}

bool ApproxDouble::operator<(const double& right) const
{
	return _value + tolerance() < right;
}

bool ApproxDouble::operator>(const ApproxDouble& right) const
{
	return _value - tolerance() > right._value + right.tolerance();
}

bool ApproxDouble::operator<(const ApproxDouble& right) const
{
	return _value + tolerance() < right._value - right.tolerance();
}

bool ApproxDouble::operator==(const ApproxDouble& right) const
{
	return !(*this > right) && !(*this < right);
}

ApproxDouble ApproxDouble::operator/(const ApproxDouble& right) const
{
	double newValue = _value / right._value;
	double newTol = std::abs((newValue + 1) / right._value) * std::max(tolerance(), right.tolerance());
	return ApproxDouble{ newValue, newTol };
}
