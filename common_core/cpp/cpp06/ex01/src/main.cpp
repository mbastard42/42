#include "serialize.hpp"

int main(void) {

	Data d;

	d.val = 42;
	std::cout << d.val << std::endl;
	std::cout << &d.val << std::endl;
	std::cout << deserialize(serialize(&d))->val << std::endl;
	std::cout << &deserialize(serialize(&d))->val << std::endl;
	return 0;
}
