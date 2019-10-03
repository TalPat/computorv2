#include "Real.hpp"

Real::Real(/* args */)
{
}

Real::~Real()
{
}

Real Real::operator+(const Real &rhs)
{
	Real result;
	double sum = _values[0] + rhs.getValues()[0];
	std::vector<double> newVal;

	newVal.push_back(sum);
	result.setValues(newVal);
	return (result);
}

Real Real::operator-(const Real &rhs)
{
	Real result;
	double difference = _values[0] - rhs.getValues()[0];
	std::vector<double> newVal;

	newVal.push_back(difference);
	result.setValues(newVal);
	return (result);

}

Real Real::operator*(const Real &rhs)
{
	Real result;
	double product = _values[0] * rhs.getValues()[0];
	std::vector<double> newVal;

	newVal.push_back(product);
	result.setValues(newVal);
	return (result);
}

Real Real::operator/(const Real &rhs)
{
	Real result;
	double quotient = _values[0] / rhs.getValues()[0];
	std::vector<double> newVal;

	newVal.push_back(quotient);
	result.setValues(newVal);
	return (result);

}

Real Real::operator^(const Real &rhs)
{
	double exponent = rhs.getValues()[0];
	Real result;
	double power = 1;
	std::vector<double> newVal;

	if (exponent >= 0 && exponent == static_cast<int>(exponent))
	{
		for (size_t i = 0; i < exponent; i++)
		{
			power *= _values[0];
		}
		newVal.push_back(power);
		result.setValues(newVal);
	} else
	{
		throw ("invalid exponent");
	}
	return (result);
}

void Real::setValues(std::vector<double> values)
{
	_values = values;
}

std::vector<double> Real::getValues(void) const
{
	return (_values);
}

std::string Real::toStr(void)
{
	std::string result;
	std::stringstream ss;

	ss << _values[0];
	result = ss.str();
	return (result);
}
