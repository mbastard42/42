#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->name = "default";
	this->hit = 100;
	this->nrg = 100;
	this->atk = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap naming constructor called" << std::endl;
	this->name = name;
	this->hit = 100;
	this->nrg = 100;
	this->atk = 30;
}

FragTrap::FragTrap(const FragTrap & trap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = trap;
}

FragTrap &	FragTrap::operator=(FragTrap const & trap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = trap.name;
	this->hit = trap.hit;
	this->nrg = trap.nrg;
	this->atk = trap.atk;
	return (*this);
}

void		FragTrap::attack(const std::string& target)
{
	if (this->hit && this->nrg)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->atk << " points of damage!" << std::endl;
		this->nrg--;
	}
}

void		FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hit -= amount;
	if (this->hit < 0)
		this->hit = 0;
}

void		FragTrap::beRepaired(unsigned int amount)
{	
	if (this->hit && this->nrg)
	{
		std::cout << "FragTrap " << this->name << " heals by " << amount << " points!" << std::endl;
		this->hit += amount;
		this->nrg--;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants to hight five" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap deconstructor called" << std::endl;
}
