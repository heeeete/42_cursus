#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>

class ScalarConverter
{
private:
	ScalarConverter(/* args*/);
	// ScalarConverter(const ScalarConverter& ref);
	~ScalarConverter();
	// ScalarConverter& operator=(const ScalarConverter& ref);
	static void charType(std::string target);
public:

	static void convert(std::string target);
};

#endif
