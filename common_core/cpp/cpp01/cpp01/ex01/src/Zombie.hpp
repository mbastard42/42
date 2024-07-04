#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

class Zombie {

	private :

	std::string name;

	public :

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void	rename_by(std::string nick);
	void	announce(void);
};

Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int N, std::string name);
