#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	this->ideas = new std::string[100];
}

Brain::Brain(Brain const & src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
}

Brain &	Brain::operator=(Brain const & src)
{
	delete [] this->ideas;
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain deconstructor called" << std::endl;
	delete [] this->ideas;
}