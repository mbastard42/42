#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default"), grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade % 151) {
	std::cout << "Bureaucrat naming constructor called" << std::endl;
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const GradeTooHighException & e) {std::cout << e.what() << std::endl;}
	catch (const GradeTooLowException & e) {std::cout << e.what() << std::endl;}
}

Bureaucrat::Bureaucrat(const Bureaucrat & b) : name(b.name), grade(b.grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat deconstructor called" << std::endl;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const & src) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->grade = src.grade;
	return *this;
}

std::string Bureaucrat::getName(void) const {
	return this->name;
}

int	Bureaucrat::getGrade(void) const {
	return this->grade;
}

void Bureaucrat::upGrade(void) {
	try {
		if (grade == 1)
			throw Bureaucrat::GradeTooHighException();
		else
			grade--;
	}
	catch (const GradeTooHighException & e) {std::cout << e.what() << std::endl;}
}

void Bureaucrat::downGrade(void) {
	try {
		if (grade == 150)
			throw Bureaucrat::GradeTooLowException();
		else
			grade++;
	}
	catch (const GradeTooLowException & e) {std::cout << e.what() << std::endl;}
}

void Bureaucrat::signForm(Form & f) {
	try {
		if (this->grade > f.getSignGrade())
			throw Bureaucrat::GradeTooLowException();
		else if (f.getSign())
			throw Bureaucrat::FormSignedException();
		else
			f.beSigned(*this);
	}
	catch (const GradeTooLowException & e) {std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;}
	catch (const FormSignedException & e) {std::cout << this->name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;}
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return o;
}
