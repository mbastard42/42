#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string	replace(std::string src, std::string s1, std::string s2)
{
	for (size_t pos = 0; s1.length() && pos < src.npos;)
	{
		pos = src.find(s1, pos);
		if (pos < src.npos)
		{
			src.erase(pos, s1.length());
			src.insert(pos, s2);
		}
	}
	return (src);
}

int	main(int ac, char **av)
{
	std::string			suffix = ".replace", s1, s2;
	std::stringstream	buffer;
	std::fstream		src;
	std::ofstream		dst;

	if (ac == 4)
	{
		s1 = av[2];
		s2 = av[3];
		src.open(av[1]);
		if (src.good())
		{
			if (s1.length())
			{
				buffer << src.rdbuf();
				dst.open(av[1] + suffix, std::ofstream::trunc);
				if (dst.good())
				{
					dst << replace(buffer.str(), s1, s2);
					dst.close();
				}
				else {std::cout << "Can't open dst file" << std::endl;}
			}
			else {std::cout << "s1 can't be empty" << std::endl;}
			src.close();
		}
		else {std::cout << "Can't open src file" << std::endl;}
	}
	else {std::cout << "Wrong number of argument" << std::endl;}
	return (0);
}
