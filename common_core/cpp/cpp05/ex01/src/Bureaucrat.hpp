#pragma once

# include "Form.hpp"
# include <string>
# include <iostream>
# include <exception>

class Form;
class Bureaucrat
{
	private :

	const std::string name;
	int grade;

	class GradeTooHighException : public std::exception {
		public :

		virtual const char * what() const throw() {return ("Grade too high exception");}
	};
	class GradeTooLowException : public std::exception {
		public :

		virtual const char * what() const throw() {return ("Grade too low exception");}
	};
	class FormSignedException : public std::exception {
		public :

		virtual const char * what() const throw() {return ("Form already signed");}
	};

	protected :

	public :

	Bureaucrat();
	Bureaucrat(std::string, int);
	Bureaucrat(const Bureaucrat &);
	~Bureaucrat();

	Bureaucrat & operator=(const Bureaucrat &);

	std::string getName(void) const ;
	int getGrade(void) const;
	void upGrade(void);
	void downGrade(void);
	void signForm(Form &);
};

std::ostream &operator<<(std::ostream &, Bureaucrat const &);
