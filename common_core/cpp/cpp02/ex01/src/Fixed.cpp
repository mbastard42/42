#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(int const intg)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(intg << this->fracbits);
}

Fixed::Fixed(float const flt)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(flt * (1 << this->fracbits)));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->raw);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw = raw;
}

int		Fixed::toInt(void) const
{
	return (this->raw >> this->fracbits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->raw / (1 << this->fracbits));
}

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
}
