#pragma once

# include "Animal.hpp"

class Cat : public Animal
{
	private :

	protected :

	public :

	Cat(void);
	Cat(Cat const & src);
	Cat & operator=(Cat const & src);
	~Cat(void);

	void		makeSound(void) const;
};