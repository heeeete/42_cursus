#include <iostream>

template<typename T>
void	iter(T *array, size_t length, void (*fn)(T&)) {
	for (size_t i = 0; i < length; i++) {
		fn(array[i]);
	}
}

template<typename T>
void	print(T &let) {
	std::cout << let << "\n";
}

template<typename T>
void	incrementByOne(T &let) {
	++let;
}
