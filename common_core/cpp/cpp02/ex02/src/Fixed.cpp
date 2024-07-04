#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->setRawBits(0);
}

Fixed::Fixed(int const intg)
{
	this->setRawBits(intg << this->fracbits);
}

Fixed::Fixed(float const flt)
{
	this->setRawBits(roundf(flt * (1 << this->fracbits)));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed(void)
{
	return ;
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

bool	Fixed::operator>=(const Fixed & fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed & fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(const Fixed & fixed)
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(const Fixed & fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

bool	Fixed::operator<(const Fixed & fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>(const Fixed & fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

Fixed	Fixed::operator+(Fixed const & fixed)
{
	Fixed fixe(*this);
	fixe.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (fixe);
}

Fixed	Fixed::operator-(Fixed const & fixed)
{
	Fixed fixe(*this);
	fixe.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (fixe);
}

Fixed	Fixed::operator*(Fixed const & fixed)
{
	Fixed fixe(*this);
	fixe.setRawBits((this->getRawBits() * fixed.getRawBits()) / (1 << this->fracbits));
	return (fixe);
}

Fixed	Fixed::operator/(Fixed const & fixed)
{
	Fixed fixe(*this);
	fixe.setRawBits((this->getRawBits() * (1 << this->fracbits)) / fixed.getRawBits());
	return (fixe);
}

Fixed	Fixed::operator++(int)
{
	Fixed fixe = *this;
	++*this;
	return (fixe);
}

Fixed	Fixed::operator--(int)
{
	Fixed fixe = *this;
	--*this;
	return (fixe);
}

Fixed &	Fixed::operator++()
{
	this->raw++;
	return (*this);
}

Fixed &	Fixed::operator--()
{
	this->raw--;
	return (*this);
}

Fixed &	Fixed::operator=(Fixed const & fixed)
{
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed &			Fixed::min(Fixed & x, Fixed & y)
{
	if (x.getRawBits() < y.getRawBits())
		return (x);
	return (y);
}

Fixed &			Fixed::max(Fixed & x, Fixed & y)
{
	if(x.getRawBits() > y.getRawBits())
		return (x);
	return (y);
}

Fixed const &	Fixed::min(Fixed const & x, Fixed const & y)
{
	if(x.getRawBits() < y.getRawBits())
		return (x);
	return (y);
}

Fixed const &	Fixed::max(Fixed const & x, Fixed const & y)
{
	if(x.getRawBits() > y.getRawBits())
		return (x);
	return (y);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
}
