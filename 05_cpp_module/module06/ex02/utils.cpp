#include "utils.hpp"

Base * generate(void){
	int idx = std::rand() % 3;

	switch (idx)
	{
	case 0 :
		return new A();
	case 1 :
		return new B();
	case 2 :
		return new C();
	default :
		return NULL;
	}
}

void identify(Base* p){
	Base* a = dynamic_cast<A*>(p);
	Base* b = dynamic_cast<B*>(p);
	Base* c = dynamic_cast<C*>(p);

	std::cout << "identify(Base* p) TEST" << "\n";
	if (p == NULL)
		std::cout << "NULL" << "\n";
	else if (a != NULL)
		std::cout << "A" << "\n";
	else if (b != NULL)
		std::cout << "B" << "\n";
	else if (c != NULL)
		std::cout << "C" << "\n";
	else
		std::cout << "FAILD IDENTIFY" << "\n";
}

void identify(Base& p){
	std::cout << "identify(Base& p) TEST" << "\n";
	try
	{
		Base& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << "\n";
	}
	catch(const std::exception& e)
	{}
	try
	{
		Base& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << "\n";
	}
	catch(const std::exception& e)
	{}
	try
	{
		Base& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
	{}
}
