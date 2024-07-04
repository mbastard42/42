#include <string>
#include <iostream>
#include <cstdlib>

int main(int ac __unused, char ** av __unused)
{
	std::string str;

	for (int i = 1; i < ac; i++)
		str += av[i];
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (size_t i = 0; i < str.size(); i++)
			str[i] = toupper(str[i]);
		std::cout << str << std::endl;
	}
	return (0);
}
