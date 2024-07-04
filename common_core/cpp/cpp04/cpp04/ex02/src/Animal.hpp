#pragma once

# include <iostream>
# include <string>

class Animal
{
	private :

	protected :

	std::string type;

	public :

	Animal(void);
	Animal(Animal const & src);
	Animal & operator=(Animal const & src);
	virtual ~Animal(void);

	std::string getType(void) const;

	virtual void makeSound(void) const = 0;

};