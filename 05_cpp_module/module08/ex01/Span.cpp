#include "Span.hpp"

Span::Span(): _size(0) {}
Span::Span(size_t size) : _size(size) {}
Span::Span(const Span& ref) {
	_size = ref._size;
	_v = ref._v;
}
Span& Span::operator=(const Span& ref) {
	if (this != &ref) {
		_size = ref._size;
		_v = ref._v;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int n){
	if (_v.size() >= _size)
		throw std::runtime_error("ERROR: oversize");
	_v.push_back(n);
}

void Span::easyAdd(size_t n){
	for (size_t i = 0; i < n; i++){
		if (_v.size() >= _size)
			throw std::runtime_error("ERROR: oversize");
		_v.push_back(i);
	}

}

int Span::shortestSpan() const {
	if (_v.size() <= 1)
		throw std::length_error("ERROR: Size must be greater than 1");
	std::vector<int> copy_v = _v;
	sort(copy_v.begin(), copy_v.end());
	int min = copy_v.at(1) - copy_v.at(0);
	for (size_t i = 2; i < copy_v.size(); i++){
		if (copy_v.at(i) - copy_v.at(i - 1) < min)
			min = copy_v.at(i) - copy_v.at(i - 1);
	}
	return (min);
}

int Span::longestSpan() const {
	if (_v.size() <= 1)
		throw std::length_error("ERROR: Size must be greater than 1");
	int max = *std::max_element(_v.begin(), _v.end());
	int min = *std::min_element(_v.begin(), _v.end());
	return (max - min);
}
