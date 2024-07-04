#pragma once

# include <string>
# include <stdlib.h>
# include <iostream>

class Base {

	public :

	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void);
void identify(Base *);
void identify(Base &);
