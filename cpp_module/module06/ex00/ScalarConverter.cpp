#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){};
// ScalarConverter::ScalarConverter(const ScalarConverter& ref) {};
ScalarConverter::~ScalarConverter() {};

void specialValues(std::string target){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (target == "nan" || target == "inf") {
		std::cout << "float: " << target << "f" << std::endl;
		std::cout << "double: " << target << std::endl;
		return ;
	}
	std::cout << "float: " << target << std::endl;
	std::cout << "double: " << target << std::endl;
}

bool strVaildCheck(std::string& target){
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
			return (true);
	}
	return false;
}

void ScalarConverter::charType(std::string target){
	if (isprint(target[0]))
		std::cout << "char: " << '\'' << target[0] << '\'' << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(target[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(target[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(target[0]) << ".0" << std::endl;
}

void ScalarConverter::convert(std::string target) {
	if (target.size() == 0)
		std::cerr << "Error : do not empty string" << std::endl;
	else if (target.size() == 1 && !isdigit(target[0])) {
		charType(target);
	}
	else {
		if (strVaildCheck(target) == false){
			return ;
		}
		else {
			specialValues(target);
		}
	}
}
