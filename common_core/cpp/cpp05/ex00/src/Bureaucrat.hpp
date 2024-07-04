#pragma once

# include <string>
# include <iostream>
# include <exception>

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
};

std::ostream &operator<<(std::ostream &, Bureaucrat const &);
