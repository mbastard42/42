#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Default animal";
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal &	Animal::operator=(Animal const & src)
{
	this->type = src.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal deconstructor called" << std::endl;
}

std::string		Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Growl" << std::endl;
}