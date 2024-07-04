#pragma once

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public Form
{
	private :

	std::string target;

	protected :

	public :

	RobotomyRequestForm();
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(const RobotomyRequestForm &);
	~RobotomyRequestForm();
	
	void execute(const Bureaucrat &) const;
};

std::ostream &operator<<(std::ostream &, RobotomyRequestForm const &);
