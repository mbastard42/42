#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog(Dog const & src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

Dog &	Dog::operator=(Dog const & src)
{
	delete this->brain;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog deconstructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wuaf" << std::endl;
}