#include "Contact.hpp"

Contact::Contact(void) {

	for (int i = 0; i < 5; i++)
		info[i].clear();
}

void	Contact::set(void) {
	std::cout << "First name: "; std::cin >> info[0];
	std::cout << "Last name: "; std::cin >> info[1];
	std::cout << "Nickname: "; std::cin >> info[2];
	std::cout << "Phone number: "; std::cin >> info[3];
	std::cout << "Darkest secret: "; std::cin >> info[4];
}

std::string Contact::get(int element) {

	return info[element];
}

void	Contact::display(void) {

	std::cout << "First name: " << info[0] << std::endl;
	std::cout << "Last name: " << info[1] << std::endl;
	std::cout << "Nickname: " << info[2] << std::endl;
	std::cout << "Phone number: " << info[3] << std::endl;
	std::cout << "Darkest secret: " << info[4] << std::endl;
}
