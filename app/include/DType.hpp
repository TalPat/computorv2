#ifndef DTYPE_HPP
#define DTYPE_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <string>
#include <sstream>

class DType
{
private:
protected:
	std::vector<double> _values;
public:
	DType(/* args */);
	~DType();

	virtual std::string toStr(void);
	virtual void setValues(std::vector<double> values);
	virtual std::vector<double> getValues(void) const;
};

#endif
