#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("shrubbery creation", 145, 137) {
	std::cout << "ShrubberyCreationForm naming constructor called" << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & f) : Form(f) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm deconstructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat & b) const {
	std::ofstream tmp;

	std::cout << b.getName() << " executed " << this->getName() << std::endl;
	tmp.open(this->target, std::ofstream::trunc);
	if (tmp.good()) {
		tmp << "/-\\" << std::endl << "\\-/" << std::endl << " |"<< std::endl;
		tmp.close();
	}
}

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const & b) {
	o << b.getName() << ", ShrubberyCreationForm sign grade " << b.getSignGrade() << " and exec grade " << b.getExecGrade() << std::endl;
	return o;
}
