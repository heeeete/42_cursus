#include "Serializer.hpp"

int main(){
	Data A;
	A.str = "Hello World";

	Data* originalPtr = &A;
	uintptr_t seriPtr = Serializer::serialize(&A);
	Data* desrPtr = Serializer::deserialize(seriPtr);
	if (originalPtr == desrPtr)
		std::cout << "originalPtr == desrPtr" << "\n";
	else
		std::cout << "originalPtr != desrPtr" << "\n";
	std::cout <<  "desrPtr = " << desrPtr->str << "\n";
	std::cout << "originalPtr = " << originalPtr->str << "\n";
}
