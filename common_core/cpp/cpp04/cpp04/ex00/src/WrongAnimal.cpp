#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Wrong animal default constructor called" << std::endl;
	this->type = "Default Wrong animal";
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "Wrong animal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src)
{
	this->type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong animal deconstructor called" << std::endl;
}

std::string		WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Growl" << std::endl;
}