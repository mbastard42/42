#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	robot("bot");

	std::cout << "hit: " << robot.get_int("hit") << std::endl;
	std::cout << "atk: " << robot.get_int("atk") << std::endl;
	std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	robot.attack("bad");
	robot.beRepaired(10);
	robot.takeDamage(5);
	std::cout << "hit: " << robot.get_int("hit") << std::endl;
	std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	robot.takeDamage(14);
	std::cout << "hit: " << robot.get_int("hit") << std::endl;
	std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	robot.attack("bad");
	for (int i = 0; i < 7; i++)
	{
		robot.beRepaired(1);
		std::cout << "hit: " << robot.get_int("hit") << std::endl;
		std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	}
	robot.attack("bad");
	robot.beRepaired(10);
	robot.takeDamage(9);
	std::cout << "hit: " << robot.get_int("hit") << std::endl;
	std::cout << "atk: " << robot.get_int("atk") << std::endl;
	std::cout << "nrg: " << robot.get_int("nrg") << std::endl;
	return 0;
}