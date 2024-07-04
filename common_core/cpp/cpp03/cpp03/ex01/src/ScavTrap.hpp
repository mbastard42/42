#pragma once

# include <string>
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :

	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(const ScavTrap &);

	ScavTrap &	operator=(const ScavTrap &);

	void	attack(const std::string&);
	void	takeDamage(unsigned int);
	void	beRepaired(unsigned int);
	void	guardGate(void);

	~ScavTrap();
};
