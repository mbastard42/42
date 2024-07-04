#include "PhoneBook.hpp"

void PhoneBook::add(void) {

	static int	i = 0;

	std::cout << "Add Contact:\n" << std::endl;
	if (i > 7) {
		std::cout << "Will replace contact " << i % 8 << "\n" << std::endl;
	}
	book[i % 8].set();
	i++;
	std::cout << std::endl;
}

void PhoneBook::search(void) {

	unsigned int	id;
	std::string		str;

	id = 8;
	if (book[0].get(0).empty()) {
		std::cout << "Search Contact:\n" << std::endl << "Empty PhoneBook" << std::endl;
	}
	else {
		while (id < 0 || id > 7 || book[id].get(4).empty()) {
			system("clear");
			std::cout << "Search Contact:\n" << std::endl;
			std::cout << "        ID|first name| last name|  nickname|" << std::endl;
			std::cout << "__________|__________|__________|__________|" << std::endl;
			for (int i = 0; (i < 8 && !book[i].get(0).empty()); i++) {
				std::cout << "         " << i << "|";
				for (int j = 0; j < 3; j++) {
					str = book[i].get(j);
					for (unsigned long k = 0; str.length() <= 10 && k < 10 - str.length(); k++) {
						std::cout << " ";
					}
					if (str.length() <= 10) {
						std::cout << str;
					} else {
						std::cout << str.substr(0, 9) << ".";
					}
					std::cout << "|";
				}
				std::cout << std::endl << "__________|__________|__________|__________|" << std::endl;
			}
			std::cout << std::endl << "Contact ID : ";
			std::cin >> id; std::cout << std::endl;
			if (!std::cin) {
				id = 8;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
		book[id].display();
	}
	std::cout << std::endl;
}
