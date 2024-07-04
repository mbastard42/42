#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->name = "default";
	this->hit = 100;
	this->nrg = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap naming constructor called" << std::endl;
	this->name = name;
	this->hit = 100;
	this->nrg = 50;
	this->atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap & trap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = trap;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & trap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = trap.name;
	this->hit = trap.hit;
	this->nrg = trap.nrg;
	this->atk = trap.atk;
	return (*this);
}

void		ScavTrap::attack(const std::string& target)
{
	if (this->hit && this->nrg)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->atk << " points of damage!" << std::endl;
		this->nrg--;
	}
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hit -= amount;
	if (this->hit < 0)
		this->hit = 0;
}

void		ScavTrap::beRepaired(unsigned int amount)
{	
	if (this->hit && this->nrg)
	{
		std::cout << "ScavTrap " << this->name << " heals by " << amount << " points!" << std::endl;
		this->hit += amount;
		this->nrg--;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " entered Gate keeper mod" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap deconstructor called" << std::endl;
}
