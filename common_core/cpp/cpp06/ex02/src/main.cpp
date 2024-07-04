#include "Base.hpp"

int main(void) {

	Base * _base = new Base;
	Base * _child = generate();

	identify(_base);
	identify(* _base);
	identify(_child);
	identify(* _child);

	delete _base;
	delete _child;
	return 0;
}
