#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Intern i;
	Bureaucrat *b = new Bureaucrat("Harry", 5);
	std::cout << std::endl;

	Form *f = i.makeForm("shrubbery creation", "yard");
	if (f) {
		b->signForm(*f);
		b->executeForm(*f);
		delete f;
		std::cout << std::endl;
	}

	f = i.makeForm("robotomy request", "henry");
	if (f) {
		b->signForm(*f);
		b->executeForm(*f);
		delete f;
		std::cout << std::endl;
	}

	f = i.makeForm("presidential pardon", "dede");
	if (f) {
		b->signForm(*f);
		b->executeForm(*f);
		delete f;
		std::cout << std::endl;
	}

	delete b;
	return (0);
}
