#pragma once

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private :

	protected :

	public :

	WrongCat(void);
	WrongCat(WrongCat const & src);
	WrongCat & operator=(WrongCat const & src);
	~WrongCat(void);
	
	void		makeSound(void) const;
};