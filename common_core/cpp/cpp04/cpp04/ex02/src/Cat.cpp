#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat(Cat const & src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

Cat &	Cat::operator=(Cat const & src)
{
	delete this->brain;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat deconstructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaw" << std::endl;
}