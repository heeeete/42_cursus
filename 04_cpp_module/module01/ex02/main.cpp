#include <iostream>

int main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*PTR = &str;
	std::string	&REF = str;

	std::cout << "	** memory address **" << std::endl;
	std::cout << "	str : " << &str << std::endl;
	std::cout << "	PTR : " << PTR << std::endl;
	std::cout << "	REF : " << &REF << std::endl;

	std::cout << "	** value **" << std::endl;
	std::cout << "	str : " << str << std::endl;
	std::cout << "	PTR : " << *PTR << std::endl;
	std::cout << "	REF : " << REF << std::endl;
}
