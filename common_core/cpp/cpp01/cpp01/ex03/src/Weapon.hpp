#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

class Weapon {

	private :

	std::string	type;

	public :

	Weapon(void);
	Weapon(std::string weapon);
	~Weapon(void);

	void		setType(std::string type);
	std::string	getType(void);
};
