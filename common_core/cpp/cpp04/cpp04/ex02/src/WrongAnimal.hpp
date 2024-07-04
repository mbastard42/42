#pragma once

# include <iostream>
# include <string>

class WrongAnimal
{
	private :

	protected :

	std::string	type;

	public :

	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	WrongAnimal & operator=(WrongAnimal const & src);
	virtual ~WrongAnimal(void);

	std::string	getType(void) const;

	void		makeSound(void) const;

};