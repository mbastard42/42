#pragma once

# include <iostream>
# include <string>

class Brain
{
	private :

	std::string *ideas;

	protected :

	public :

	Brain(void);
	Brain(Brain const & src);
	Brain & operator=(Brain const & src);
	virtual ~Brain(void);

};