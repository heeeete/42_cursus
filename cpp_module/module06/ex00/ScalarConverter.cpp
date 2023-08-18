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

void putNum(double value, int type){
	if (type == SPC_VALUE || value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(value) << "\n";
	std::cout << std::fixed<<"float: " << std::setprecision(1) << static_cast<float>(value) << "f" << "\n";
	std::cout << "double: " << static_cast<double>(value) << "\n";
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
			std::cout << "char: \'" << static_cast<char>(_value) << "\'"  << "\n";
		putNum(_value, _type);
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
	return INTEGER;
}

int ScalarConverter::strVaildCheck(std::string& target){
	int i = 0;
	char sign = 0;
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
