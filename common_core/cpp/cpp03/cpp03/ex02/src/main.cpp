#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	robot("bot");

	std::cout << "hit: " << robot.get_int("hit") << std::endl;
	std::cout << "atk: " << robot.get_int("atk") << std::endl;
	std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	robot.attack("bad");
	robot.beRepaired(10);
	robot.takeDamage(5);
	robot.highFivesGuys();
	std::cout << "hit: " << robot.get_int("hit") << std::endl;
	std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	return 0;
}