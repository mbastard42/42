#pragma once

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :

	bool signed_form;
	const std::string name;
	const int sign_grade, exec_grade;

	class GradeTooHighException : public std::exception {
		public :

		virtual const char * what() const throw() {return ("Form grade too high exception");}
	};
	class GradeTooLowException : public std::exception {
		public :

		virtual const char * what() const throw() {return ("Form grade too low exception");}
	};

	protected :

	public :

	Form();
	Form(std::string, int, int);
	Form(const Form &);
	~Form();

	Form & operator=(const Form &);

	int getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getSign(void) const;
	std::string getName(void) const ;
	void beSigned(const Bureaucrat &);
};

std::ostream &operator<<(std::ostream &, Form const &);
