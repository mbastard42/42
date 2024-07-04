#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &	Dog::operator=(Dog const & src)
{
	this->type = src.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog deconstructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wuaf" << std::endl;
}