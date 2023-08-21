#include "ScalarConverter.hpp"

enum {
    NOT_A_NUMBER,
    INTEGER,
    FLOAT,
	DOUBLE,
	SPC_VALUE,
};

int ScalarConverter::_type = 0;
double ScalarConverter::_value = 0.0;
bool ScalarConverter::_minusSign = false;
ScalarConverter::ScalarConverter(){
	_type = 0;
	_value = 0;
};
ScalarConverter::ScalarConverter(const ScalarConverter& ref){
	*this = ref;
};
ScalarConverter::~ScalarConverter(){};
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ref){
	if (this == &ref)
		return *this;
	_type = ref._type;
	_value = ref._value;
	return *this;
};

void putInt(double n) {
	if (n > INT_MAX || n < INT_MIN)
	{
		std::cout << "int: impossible" << "\n";
		std::cout << "float: impossible" << "\n";
		std::cout << "double: impossible" << "\n";
	}
	else
	{
		int value = static_cast<int>(n);
		std::cout << "int: " << value << "\n";
		std::cout << std::fixed<<"float: " << std::setprecision(1) << static_cast<float>(value) << "f" << "\n";
		std::cout << "double: " << static_cast<double>(value) << "\n";
	}
}

void putFloat(double n) {
	float value = static_cast<float>(n);
	if (n > INT_MAX || n < INT_MIN)
		std::cout << "int: impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(n) << "\n";
	std::cout << std::fixed<< "float: " << std::setprecision(1) << value << "f" << "\n";
	std::cout << "double: " << static_cast<double>(value) << "\n";
}

void putDouble(double n) {

	if (n > INT_MAX || n < INT_MIN)
		std::cout << "int: impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(n) << "\n";
	std::cout << std::fixed<<"float: " << std::setprecision(1) << static_cast<float>(n) << "f" << "\n";
	std::cout << "double: " << n << "\n";
}

void putSpcValue(double n){
	std::cout << "int: impossible" << "\n";
	std::cout << "float: " << n << "f" << "\n";
	std::cout << "double: " << n << "\n";
}

void otherChar(int _type, double value){
	if (_type == INTEGER) {
		int n = static_cast<int>(value);
		std::cout << "char: \'" << static_cast<char>(n) << "\'"  << "\n";
	}
	else if (_type == FLOAT){
		float n = static_cast<float>(value);
		std::cout << "char: \'" << static_cast<char>(n) << "\'"  << "\n";
	}
	else if (_type == DOUBLE){
		std::cout << "char: \'" << static_cast<char>(value) << "\'"  << "\n";
	}
}

void ScalarConverter::numToOther(std::string target){
	try
	{
		_value = std::strtod(target.c_str(), NULL);
		if (_minusSign == true)
			_value *= -1;
		if (_type == SPC_VALUE)
			std::cout << "char: impossible" << "\n";
		else if (!std::isprint(_value))
			std::cout << "char: Non displayable" << "\n";
		else
			otherChar(_type, _value);
		if (_type == INTEGER)
			putInt(_value);
		else if (_type == FLOAT)
			putFloat(_value);
		else if (_type == DOUBLE)
			putDouble(_value);
		else
			putSpcValue(_value);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int typeSearch(std::string target){
	bool hasF = false;
	bool hasDot = false;

	if (target[target.size() - 1] == 'f'){
		if (!std::isdigit(target[target.size() - 2]))
			return NOT_A_NUMBER;
		hasF = true;
		}
	else if (!std::isdigit(target[target.size() - 1])) return NOT_A_NUMBER;
	for (unsigned long i = 0; target[i]; i++) {
		if (target[i] == '.'){
			if (hasDot || target[0] == '.')
				return NOT_A_NUMBER;
			hasDot = true;
		} else if (target.size() - 1 != i && !std::isdigit(target[i]))
			return NOT_A_NUMBER;
	}
	if (hasDot && !hasF) return DOUBLE;
	else if (hasDot && hasF) return FLOAT;
	else if (!hasDot && hasF) return NOT_A_NUMBER;
	return INTEGER;
}

int ScalarConverter::strVaildCheck(std::string& target){
	int i = 0;

	std::string _value[4] = {"nan", "nanf", "inf", "inff"};

	for (; target[i] == ' '; i++) ;
	if (target[i] == '-' || target[i] == '+'){
		if (target[i] == '-')
			_minusSign = true;
		i++;
	}
	target.erase(0,i);
	for(i = 0 ; i < 4 ; i++) {
		if (target == _value[i])
			return (SPC_VALUE);
	}
	return typeSearch(target);

}

void ScalarConverter::charType(std::string target){
	if (isprint(target[0]))
		std::cout << "char: " << '\'' << target[0] << '\'' << "\n";
	else
		std::cout << "char: Non displayable" << "\n";
	std::cout << "int: " << static_cast<int>(target[0]) << "\n";
	std::cout << "float: " << static_cast<float>(target[0]) << ".0f" << "\n";
	std::cout << "double: " << static_cast<double>(target[0]) << ".0" << "\n";
}

void ScalarConverter::convert(std::string target) {
	if (target.size() == 0)
		std::cerr << "Error : do not empty string" << "\n";
	else if (target.size() == 1 && !isdigit(target[0])) {
		charType(target);
	}
	else {
		_type = strVaildCheck(target);
		if (_type == NOT_A_NUMBER){
			std::cerr << "Error : Invaild string" << "\n";
		}
		else
			numToOther(target);
	}
}
