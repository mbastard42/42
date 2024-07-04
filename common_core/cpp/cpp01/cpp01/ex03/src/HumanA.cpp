#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {

	std::cout << name << " spawned with weapon " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void) {

	std::cout << name << " despawned" << std::endl;
}

void	HumanA::rename_by(std::string name) {

	this->name = name;
}

void	HumanA::setWeapon(Weapon &weapon) {

	this->weapon = weapon;
}

void	HumanA::attack(void) {

	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
