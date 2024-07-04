#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const & src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat &	Cat::operator=(Cat const & src)
{
	this->type = src.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat deconstructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaw" << std::endl;
}