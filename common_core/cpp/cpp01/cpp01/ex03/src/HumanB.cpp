#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name) {

	this->weapon = NULL;
	std::cout << name << " spawned" << std::endl;
}

HumanB::~HumanB(void) {

	std::cout << name << " despawned"<< std::endl;
}

void	HumanB::rename_by(std::string name) {

	this->name = name;
}

void	HumanB::setWeapon(Weapon &weapon) {

	this->weapon = &weapon;
}

void	HumanB::attack(void) {

	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
