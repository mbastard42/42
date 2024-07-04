#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form() {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm_form", 72, 45) {
	std::cout << "RobotomyRequestForm naming constructor called" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & f) : Form(f) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm deconstructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat & b) const {
	static int half = 0;
	std::cout << b.getName() << " executed " << this->getName() << std::endl;
	std::cout << "drill noise" << std::endl;
	if (++half % 2)
		std::cout << this->target << " has been robotised with success" << std::endl;
	else
		std::cout << "failed to robotise " << this->target << std::endl;
}

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const & b) {
	o << b.getName() << ", RobotomyRequestForm sign grade " << b.getSignGrade() << " and exec grade " << b.getExecGrade() << std::endl;
	return o;
}
