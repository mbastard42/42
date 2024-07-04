#include "PhoneBook.hpp"

int main(void) {
    
    PhoneBook   phone;
    std::string str;

    str.clear();
    std::cout << "command: ";
    while (std::getline(std::cin, str)) {
        system("clear");
        if (str == "ADD") {
            phone.add();
        }
        else if (str == "SEARCH") {
            phone.search();
        }
        else if (str == "EXIT") {
            exit(0);
        }
        else {
            std::cout << "Available commands :\n\nADD\nSEARCH\nEXIT\n" << std::endl;
        }
        std::cout << "command: ";
    }
    return (0);
}