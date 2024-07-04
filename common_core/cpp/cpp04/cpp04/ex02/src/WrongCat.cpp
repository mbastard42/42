#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat &	WrongCat::operator=(WrongCat const & src)
{
	this->type = src.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat deconstructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong miaw" << std::endl;
}