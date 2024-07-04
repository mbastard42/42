#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat *b = new Bureaucrat("Harry", 5);
	std::cout << std::endl;

	Form *f = new ShrubberyCreationForm("yard");
	b->executeForm(*f);
	b->signForm(*f);
	b->signForm(*f);
	b->executeForm(*f);
	delete f;
	std::cout << std::endl;

	f = new RobotomyRequestForm("robot");
	b->signForm(*f);
	b->executeForm(*f);
	b->executeForm(*f);
	delete f;
	std::cout << std::endl;

	f = new PresidentialPardonForm("robot");
	b->signForm(*f);
	b->executeForm(*f);
	delete f;
	std::cout << std::endl;

	delete b;
	return 0;
}
