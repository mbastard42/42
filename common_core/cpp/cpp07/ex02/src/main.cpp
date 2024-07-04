#include "Array.hpp"

int main(void) {

	Array<int> itab(3);
	Array<int> afftab = itab;
	Array<int> cpytab(itab);
	Array<std::string> stab(3);

	try {
		std::cout << "itab :" << std::endl;
		std::cout << itab;
		itab[2] = 42;
		std::cout << "modified itab :" << std::endl;
		std::cout << itab;
		std::cout << "unmodified cpytab :" << std::endl;
		std::cout << cpytab;
		afftab[1] = 42;
		std::cout << "unmodified itab :" << std::endl;
		std::cout << itab;
		std::cout << "modified afftab :" << std::endl;
		std::cout << afftab;
		stab[1] = "42";
		std::cout << "stab :" << std::endl;
		std::cout << stab;
	}
	catch (std::exception & e) {std::cout << "operator [] overflow" << std::endl;}
	return 0;
}
