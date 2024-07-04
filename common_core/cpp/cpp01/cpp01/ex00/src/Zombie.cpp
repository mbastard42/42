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

void	Zombie::announce(void) {

	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

