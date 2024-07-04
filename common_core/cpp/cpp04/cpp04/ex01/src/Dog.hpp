#pragma once

# include "Brain.hpp"
# include "Animal.hpp"

class Dog : public Animal
{
	private :

	Brain *brain;

	protected :

	public :

	Dog(void);
	Dog(Dog const & src);
	Dog & operator=(Dog const & src);
	~Dog(void);

	void		makeSound(void) const;
};