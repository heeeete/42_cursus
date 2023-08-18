#include "ScalarConverter.hpp"
enum {
    NOT_A_NUMBER,
    INTEGER,
    FLOAT,
	DOUBLE,
	SPC_VALUE,
};

int ScalarConverter::_type = 0;
ScalarConverter::ScalarConverter(){};
// ScalarConverter::ScalarConverter(const ScalarConverter& ref) {};
ScalarConverter::~ScalarConverter() {};

void intToOther(std::string target, int type){
	try
	{
		double value = std::strtod(target.c_str(), NULL);
		if (type == INTEGER)
			value = static_cast<int>(value);
		else if (type == FLOAT)
			value = static_cast<float>(value);

		if (type == SPC_VALUE){
			std::cout << "char: impossible" << "\n";
			std::cout << "int: impossible" << "\n";
		} else if (type == INTEGER || type == FLOAT || type == DOUBLE){
			if (!std::isprint(value))
				std::cout << "char: Non displayable" << "\n";
			else
				std::cout << "char: \'" << static_cast<char>(value) << "\'"  << "\n";

			if (type == INTEGER) {
				std::cout << "int : " << value << "\n";
				std::cout << std::fixed<<"float: " << std::setprecision(1) << static_cast<float>(value) << "f" << "\n";
				std::cout << "double: " << static_cast<double>(value) << "\n";
			} else if (type == FLOAT) {
				std::cout << "int : " << static_cast<int>(value) << "\n";
				std::cout << std::fixed<<"float: " << std::setprecision(1) << value << "f" << "\n";
				std::cout << "double: " << static_cast<double>(value) << "\n";
			} else if (type == DOUBLE) {
				std::cout << "int : " << static_cast<int>(value) << "\n";
				std::cout << std::fixed<<"float: " << std::setprecision(1) << static_cast<float>(value) << "f" << "\n";
				std::cout << "double: " << value << "\n";
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int typeSearch(std::string target){
	bool hasF = false;
	bool hasDot = false;

	if (target[target.size() - 1] == 'f') hasF = true;
	for (int i = 0; target[i]; i++) {
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

int strVaildCheck(std::string& target){
	int i = 0;
	char sign;
	std::string value[4] = {"nan", "nanf", "inf", "inff"};

	for (; target[i] == ' '; i++) ;
	if (target[i] == '-' || target[i] == '+'){
		i++;
		if (target[i] == '-')
			sign = '-';
	}
	target.erase(0,i);
	for(i = 0 ; i < 4 ; i++) {
		if (target == value[i])
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
			intToOther(target, _type);
	}
}
