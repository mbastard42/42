#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "default";
	this->hit = 10;
	this->nrg = 10;
	this->atk = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap naming constructor called" << std::endl;
	this->name = name;
	this->hit = 10;
	this->nrg = 10;
	this->atk = 0;
}

ClapTrap::ClapTrap(const ClapTrap & trap)
{
	std::cout << "Claptrap copy constructor called" << std::endl;
	*this = trap;
}

int			ClapTrap::get_int(std::string target)
{
	if (target == "hit")
		return (this->hit);
	if (target == "nrg")
		return (this->nrg);
	if (target == "atk")
		return (this->atk);
	return (0);
}

std::string	ClapTrap::get_string(std::string target)
{
	if (target == "name")
		return (this->name);
	return (NULL);
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & trap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = trap.name;
	this->hit = trap.hit;
	this->nrg = trap.nrg;
	this->atk = trap.atk;
	return (*this);
}

void		ClapTrap::attack(const std::string& target)
{
	if (this->hit && this->nrg)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->atk << " points of damage!" << std::endl;
		this->nrg--;
	}
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hit -= amount;
	if (this->hit < 0)
		this->hit = 0;
}

void		ClapTrap::beRepaired(unsigned int amount)
{	
	if (this->hit && this->nrg)
	{
		std::cout << "ClapTrap " << this->name << " heals by " << amount << " points!" << std::endl;
		this->hit += amount;
		this->nrg--;
	}
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap deconstructor called" << std::endl;
}
