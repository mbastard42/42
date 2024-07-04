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

	Fixed &	operator=(const Fixed & fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	int		toInt(void) const;
	float	toFloat(void) const;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed);
