#pragma once

# include <string>
# include <iostream>

class ClapTrap
{
	std::string	name;
	int			hit, nrg, atk;

	public :

	ClapTrap();
	ClapTrap(std::string);
	ClapTrap(const ClapTrap &);

	int			get_int(std::string);
	std::string	get_string(std::string);

	ClapTrap &	operator=(const ClapTrap &);

	void	attack(const std::string&);
	void	takeDamage(unsigned int);
	void	beRepaired(unsigned int);

	~ClapTrap();
};
