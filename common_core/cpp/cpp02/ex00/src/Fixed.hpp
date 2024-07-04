#pragma once

# include <string>
# include <iostream>

class Fixed
{
	int					raw;
	static const int	fracbits = 8;

	public :

	Fixed();
	Fixed(const Fixed&);

	~Fixed();

	Fixed &operator=(const Fixed & fixed);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};
