#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form() {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm_form", 25, 5) {
	std::cout << "PresidentialPardonForm naming constructor called" << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & f) : Form(f) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm deconstructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat & b) const {
	std::cout << b.getName() << " executed " << this->getName() << std::endl;
	std::cout << this->target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const & b) {
	o << b.getName() << ", PresidentialPardonForm sign grade " << b.getSignGrade() << " and exec grade " << b.getExecGrade() << std::endl;
	return o;
}
