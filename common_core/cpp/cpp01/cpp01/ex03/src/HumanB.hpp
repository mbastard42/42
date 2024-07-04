#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include "Weapon.hpp"

class HumanB {

	private :

	std::string	name;
	Weapon		*weapon;

	public :

	HumanB(std::string name);
	~HumanB(void);

	void	rename_by(std::string name);
	void	setWeapon(Weapon &weapon);
	void	attack(void);
};
