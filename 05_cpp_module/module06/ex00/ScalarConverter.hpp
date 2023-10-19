#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& ref);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &ref);
	static void charType(std::string target);
	static void numToOther(std::string target);
	static int strVaildCheck(std::string& target);
	static int _type;
	static double _value;
	static bool _minusSign;
public:
	static void convert(std::string target);
};

#endif
