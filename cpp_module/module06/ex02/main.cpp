#include "utils.hpp"

int main(){
	std::srand(time(NULL));
	Base* test = generate();
	Base& ref = *test;
	identify(test);
	identify(ref);

	delete test;
	return 0;
}
