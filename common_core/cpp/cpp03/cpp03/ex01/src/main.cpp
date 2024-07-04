#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	robot("bot");

	std::cout << "hit: " << robot.get_int("hit") << std::endl;
	std::cout << "atk: " << robot.get_int("atk") << std::endl;
	std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	robot.attack("bad");
	robot.beRepaired(10);
	robot.takeDamage(5);
	robot.guardGate();
	std::cout << "hit: " << robot.get_int("hit") << std::endl;
	std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	return 0;
}