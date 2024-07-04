#include "Zombie.hpp"

Zombie::Zombie(void) {

	name.clear();
}

Zombie::Zombie(std::string nick) {

	name = nick;
}

Zombie::~Zombie(void) {

	std::cout << name << " despawned" << std::endl;
}

void	Zombie::rename_by(std::string nick) {

	name = nick;
}

void	Zombie::announce(void) {

	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie	*newZombie(std::string name) {

	Zombie	*zomb;

	zomb = new Zombie(name);
	return (zomb);
}
