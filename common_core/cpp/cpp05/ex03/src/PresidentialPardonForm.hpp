#pragma once

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public Form
{
	private :

	std::string target;

	protected :

	public :

	PresidentialPardonForm();
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(const PresidentialPardonForm &);
	~PresidentialPardonForm();
	
	void execute(const Bureaucrat &) const;
};

std::ostream &operator<<(std::ostream &, PresidentialPardonForm const &);
