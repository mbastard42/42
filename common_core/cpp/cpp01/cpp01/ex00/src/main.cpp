#include "Zombie.hpp"

int main(void) {

	Zombie	*zomb;

	zomb = newZombie("Zombie");
	zomb->announce();
	randomChump("Chump");
	delete zomb;
	return (0);
}
