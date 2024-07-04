#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b("bot", 42);
	Form f("impot", 42, 150);
	b.signForm(f);
	b.signForm(f);
}
