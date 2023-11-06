#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template<typename T>
class Array
{
private:
	T*				_array;
	unsigned int	_size;
public:
	Array() {
		_array = new T[0];
		_size = 0;
	}
	Array(unsigned int size) {
		_array = new T[size];
		_size = size;
	}
	Array(const Array& obj) {
		_array = new T[obj._size];
		_size = obj._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = obj._array[i];
	}
	Array& operator=(const Array& obj) {
		if (this == &obj)
			return *this;
		delete[] _array;
		_array = new T[obj._size];
		_size = obj._size;
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = obj._array[i];
		return *this;
	}
	T& operator[](unsigned int i) {
		if (_size <= i)
			throw std::out_of_range("OUT OF RANGE!!");
		return _array[i];
	}
	unsigned int size(){
		return _size;
	}
	~Array() {
		delete[] _array;
	}
};

template<typename T>
void print(Array<T> arr){
	for (unsigned int i = 0; i < arr.size() ; i++)
		std::cout << arr[i];
	std::cout << "\n";
}

#endif
