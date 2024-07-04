#include "Weapon.hpp"

Weapon::Weapon(void) {

	type.clear();
	std::cout << "a weapon appeared" << std::endl;
}

Weapon::Weapon(std::string type) {

	this->type = type;
	std::cout << type << " appeared" << std::endl;
}

Weapon::~Weapon(void) {

	std::cout << type << " lost forever" << std::endl;
}

void	Weapon::setType(std::string type) {

	this->type = type;
}

std::string	Weapon::getType(void) {

	return (type);
}
