#include "..\include\ApproxDouble.hpp"
#include "..\include\ApproxDouble.hpp"
#include "ApproxDouble.hpp"

ApproxDouble::ApproxDouble(double value, double epsilon):
	_value(value),
	_epsilon(epsilon)
{
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
