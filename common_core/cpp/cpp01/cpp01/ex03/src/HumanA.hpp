#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include "Weapon.hpp"

class HumanA {

	private :

	std::string	name;
	Weapon		&weapon;

	public :

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void	rename_by(std::string name);
	void	setWeapon(Weapon &weapon);
	void	attack(void);
};
