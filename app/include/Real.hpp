#ifndef REAL_HPP
#define REAL_HPP

#include "DType.hpp"

class Real : public DType
{
private:
	/* data */
public:
	Real(/* args */);
	~Real();

	Real operator+(const Real &rhs);
	Real operator-(const Real &rhs);
	Real operator*(const Real &rhs);
	Real operator/(const Real &rhs);
	Real operator^(const Real &rhs);

	void setValues(std::vector<double> values);
	std::vector<double> getValues(void) const;
	std::string toStr(void);
};

#endif
