#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					value;
	const static int	bit = 8;
public:
	Fixed( void );
	Fixed (const int value);
	Fixed (const float value);
	Fixed(const Fixed& obj);
	~Fixed( void );
	Fixed&	operator=(const Fixed& obj);
	Fixed&	operator++( void );
	const Fixed	operator++(int);
	Fixed&	operator--( void );
	const Fixed	operator--(int);
	Fixed	operator*(const Fixed& obj);
	Fixed	operator/(const Fixed& obj);
	Fixed	operator+(const Fixed& obj);
	Fixed	operator-(const Fixed& obj);
	bool	operator>(const Fixed& obj);
	bool	operator<(const Fixed& obj);
	bool	operator>=(const Fixed& obj) const;
	bool	operator<=(const Fixed& obj) const;
	bool	operator==(const Fixed& obj);
	bool	operator!=(const Fixed& obj);
	int		getRawBits( void ) const;
	void	setRawBits(int const raw);
	int		toInt( void ) const;
	float	toFloat( void ) const;
	static	Fixed& max(Fixed& obj1, Fixed& obj2);
	static	Fixed& min(Fixed& obj1, Fixed& obj2);
	const static	Fixed& max(const Fixed& obj1, const Fixed& obj2);
	const static	Fixed& min(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator<<(std::ostream &temp, const Fixed& fixed);
#endif
