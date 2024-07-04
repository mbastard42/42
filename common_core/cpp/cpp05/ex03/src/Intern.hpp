#pragma once

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string>
# include <iostream>
# include <exception>

class Form;

class Intern
{
	private :

	class UnknowFormException : public std::exception {
		public :

		virtual const char * what() const throw() {return ("Unknow Form requested");}
	};

	protected :

	public :

	Intern();
	Intern(const Intern &);
	~Intern();

	Intern & operator=(const Intern &);

	Form * makeForm(std::string, std::string);
};