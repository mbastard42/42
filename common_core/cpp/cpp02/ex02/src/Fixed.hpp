#pragma once

# include <cmath>
# include <string>
# include <iostream>

class Fixed
{
	int					raw;
	static const int	fracbits = 8;

	public :

	Fixed();
	Fixed(int const intg);
	Fixed(float const flt);
	Fixed(const Fixed &);

	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	int		toInt(void) const;
	float	toFloat(void) const;

	bool	operator>=(const Fixed & fixed);
	bool	operator<=(const Fixed & fixed);
	bool	operator==(const Fixed & fixed);
	bool	operator!=(const Fixed & fixed);
	bool	operator<(const Fixed & fixed);
	bool	operator>(const Fixed & fixed);
	Fixed	operator+(const Fixed & fixed);
	Fixed	operator-(const Fixed & fixed);
	Fixed	operator*(const Fixed & fixed);
	Fixed	operator/(const Fixed & fixed);
	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed &	operator++(void);
	Fixed &	operator--(void);
	Fixed &	operator=(const Fixed & fixed);

	static Fixed &			min(Fixed & x, Fixed & y);
	static Fixed &			max(Fixed & x, Fixed & y);
	static Fixed const &	min(Fixed const & x, Fixed const & y);
	static Fixed const &	max(Fixed const & x, Fixed const & y);
};

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed);
