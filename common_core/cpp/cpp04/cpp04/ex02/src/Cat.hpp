#pragma once

# include "Brain.hpp"
# include "Animal.hpp"

class Cat : public Animal
{
	private :

	Brain *brain;

	protected :

	public :

	Cat(void);
	Cat(Cat const & src);
	Cat & operator=(Cat const & src);
	~Cat(void);

	void		makeSound(void) const;
};