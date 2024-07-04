#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat a("maxbot", 2);
	std::cout << a;
	a.upGrade();
	std::cout << a;

	Bureaucrat b(a);
	std::cout << b;

	Bureaucrat c("min bot", 149);
	std::cout << c;
	c.downGrade();
	std::cout << c;
}
