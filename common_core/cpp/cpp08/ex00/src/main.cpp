#include "easyfind.hpp"

int main(void) {

	std::vector<int> vec(10);
	for (int i = 0; i < 10; i++)
		vec[i] = i;

	int test = 5;
	std::cout << test << (easyfind(vec, test) ? " is" : " ain't") << " in container" << std::endl;
	test = 11;
	std::cout << test << (easyfind(vec, test) ? " is" : " ain't") << " in container" << std::endl;

	std::string str = "salut";

	int chartest = 's';
	std::cout << static_cast<char>(chartest) << (easyfind(str, chartest) ? " is" : " ain't") << " in container" << std::endl;
	chartest = 'f';
	std::cout << static_cast<char>(chartest) << (easyfind(str, chartest) ? " is" : " ain't") << " in container" << std::endl;
	return 0;
}
