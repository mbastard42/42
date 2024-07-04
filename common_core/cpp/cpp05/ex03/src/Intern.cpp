#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern & b __unused) {
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern deconstructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & src __unused) {
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Form * Intern::makeForm(std::string name, std::string target){

	std::cout << "Intern creates " << name << std::endl;
	try {
		if (name != "shrubbery creation" && name != "robotomy request" && name != "presidential pardon")
			throw Intern::UnknowFormException();
		switch ((int)name[0]) {
			case (int)'s' :
				return new ShrubberyCreationForm(target);
			case (int)'r' :
				return new RobotomyRequestForm(target);
			case (int)'p' :
				return new PresidentialPardonForm(target);
		}
	}
	catch (const UnknowFormException & e) {std::cout << e.what() << std::endl;}
	return (NULL);
}