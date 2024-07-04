#pragma once

# include <fstream>
# include <sstream>
# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	private :

	std::string target;

	protected :

	public :

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string);
	ShrubberyCreationForm(const ShrubberyCreationForm &);
	~ShrubberyCreationForm();
	
	void execute(const Bureaucrat &) const;
};

std::ostream &operator<<(std::ostream &, ShrubberyCreationForm const &);
