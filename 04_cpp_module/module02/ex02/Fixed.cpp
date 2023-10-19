#include "Fixed.hpp"

Fixed::Fixed( void ) {
	this->value = 0;
};

Fixed::Fixed(const Fixed& obj) {
	*this = obj;
}

Fixed::Fixed(int value) {
	this->value = value << this->bit;
}

Fixed::Fixed (const float value) {
	this->value = roundf(value * (1 << this->bit));
}

Fixed::~Fixed( void ) {
}

Fixed& Fixed::operator=(const Fixed& obj) {
	if (this != &obj) {
		this->value = obj.getRawBits();
	}
	return *this;
}

Fixed&	Fixed::operator++( void ) {
	this->value++;
	return *this;
}

const Fixed	Fixed::operator++(int) {
	Fixed	temp = *this;
	this->value++;
	return temp;
}

Fixed&	Fixed::operator--( void ) {
	this->value++;
	return *this;
}

const Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;
	this->value++;
	return temp;
}

Fixed	Fixed::operator*(const Fixed& obj) {
	Fixed	temp(this->toFloat() * obj.toFloat());
	return temp;
}

Fixed	Fixed::operator/(const Fixed& obj) {
	Fixed	temp(this->toFloat() / obj.toFloat());
	return temp;
}

Fixed	Fixed::operator+(const Fixed& obj) {
	Fixed	temp(this->toFloat() + obj.toFloat());
	return temp;
}

Fixed	Fixed::operator-(const Fixed& obj) {
	Fixed	temp(this->toFloat() - obj.toFloat());
	return temp;
}

bool	Fixed::operator<(const Fixed& obj) {
	if (this->toFloat() < obj.toFloat())	return true;
	return false;
}

bool	Fixed::operator>(const Fixed& obj) {
	if (this->toFloat() > obj.toFloat())	return true;
	return false;
}

bool	Fixed::operator>=(const Fixed& obj) const {
	if (this->toFloat() >= obj.toFloat())	return true;
	return false;
}

bool	Fixed::operator<=(const Fixed& obj) const {
	if (this->toFloat() <= obj.toFloat())	return true;
	return false;
}

bool	Fixed::operator==(const Fixed& obj) {
	if (this->toFloat() == obj.toFloat())	return true;
	return false;
}

bool	Fixed::operator!=(const Fixed& obj) {
	if (this->toFloat() != obj.toFloat())	return true;
	return false;
}

std::ostream& operator<<(std::ostream &temp, const Fixed& fixed) {
	temp << fixed.toFloat();
	return temp;
}

int	Fixed::getRawBits( void ) const {
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << this->bit));
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->bit);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {
	if (obj1 >= obj2)	return obj1;
	return obj2;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {
	if (obj1 <= obj2)	return obj1;
	return obj2;
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {
	if (obj1 >= obj2)	return obj1;
	return obj2;
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {
	if (obj1 <= obj2)	return obj1;
	return obj2;
}
