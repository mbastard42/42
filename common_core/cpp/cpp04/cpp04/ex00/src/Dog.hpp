#pragma once

# include "Animal.hpp"

class Dog : public Animal
{
	private :

	protected :

	public :

	Dog(void);
	Dog(Dog const & src);
	Dog & operator=(Dog const & src);
	~Dog(void);

	void		makeSound(void) const;
};