#include "ApproxDouble.hpp"
#include <utility>

ApproxDouble::ApproxDouble(double value, double epsilon):
	_value(value),
	_epsilon(epsilon)
{
}

bool ApproxDouble::equal(const ApproxDouble& left, const ApproxDouble& right, double tolerance)
{
	double sumTolerance = tolerance + std::max(left.tolerance(), right.tolerance());
	return (left._value - sumTolerance) < right._value &&
		(left._value + sumTolerance) > right._value;
}

bool ApproxDouble::less(const ApproxDouble& left, const ApproxDouble& right, double tolerance)
{
	double sumTolerance = tolerance + std::max(left.tolerance(), right.tolerance());
	return (left._value + sumTolerance) < right._value;
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
	return _value * (1 - _epsilon) > right;
}

bool ApproxDouble::operator<(const double& right) const
{
	return _value * (1 + _epsilon) < right;
}

bool ApproxDouble::operator>(const ApproxDouble& right) const
{
	return _value * (1 - _epsilon) > right._value * (1 + right._epsilon);
}

bool ApproxDouble::operator<(const ApproxDouble& right) const
{
	return _value * (1 + _epsilon) < right._value * (1 - right._epsilon);
}

bool ApproxDouble::operator==(const ApproxDouble& right) const
{
	return !(*this > right) && !(*this < right);
}

ApproxDouble ApproxDouble::operator/(const ApproxDouble& other) const
{
	return ApproxDouble{ _value / other._value, _epsilon + other._epsilon };
}
