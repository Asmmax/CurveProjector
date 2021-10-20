#include "ApproxDouble.hpp"

ApproxDouble::ApproxDouble(double value, double epsilon):
	_value(value),
	_epsilon(epsilon)
{
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

ApproxDouble ApproxDouble::operator/(const ApproxDouble& other) const
{
	return ApproxDouble{ _value / other._value, _epsilon + other._epsilon };
}
