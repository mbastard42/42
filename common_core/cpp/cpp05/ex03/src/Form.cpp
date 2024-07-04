#include "Form.hpp"

Form::Form(void) : signed_form(false), name("default"), sign_grade(150), exec_grade(150) {
	std::cout << "Form default constructor called" << std::endl;
	this->signed_form = false;
}

Form::Form(std::string name, int sign, int exec) : signed_form(false), name(name), sign_grade(sign % 151), exec_grade(exec % 151) {
	std::cout << "Form naming constructor called" << std::endl;
	try {
		if (sign < 1 || exec < 1)
			throw Form::GradeTooHighException();
		if (sign > 150 || exec > 150)
			throw Form::GradeTooLowException();
	}
	catch (const GradeTooHighException & e) {std::cout << e.what() << std::endl;}
	catch (const GradeTooLowException & e) {std::cout << e.what() << std::endl;}
}

Form::Form(const Form & f) : signed_form(f.signed_form), name(f.name), sign_grade(f.sign_grade), exec_grade(f.exec_grade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form deconstructor called" << std::endl;
}

Form &	Form::operator=(Form const & src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->signed_form = src.signed_form;
	return *this;
}

int	Form::getSignGrade(void) const {
	return this->sign_grade;
}

int	Form::getExecGrade(void) const {
	return this->exec_grade;
}

bool Form::getSign(void) const {
	return this->signed_form;
}

std::string Form::getName(void) const {
	return this->name;
}

void Form::beSigned(const Bureaucrat & b) {
	this->signed_form = true;
	std::cout << b.getName() << " signed " << this->name << std::endl;
}

std::ostream &	operator<<(std::ostream & o, Form const & b) {
	o << b.getName() << ", Form sign grade " << b.getSignGrade() << " and exec grade " << b.getExecGrade() << std::endl;
	return o;
}
