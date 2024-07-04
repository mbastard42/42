#include "iter.hpp"

int main(void) {

	int itab[3] = {3, 1, 4};
	std::string stab[3] = {"salut", "42", "test"};

	iter(itab, 3, print);
	iter(stab, 3, print);
	return 0;
}
