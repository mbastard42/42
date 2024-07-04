#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* i = new Cat();
	std::cout << i->getType() << " noise: ";
	i->makeSound();
	delete i;
	std::cout << std::endl;

	const Animal* j = new Dog();
	std::cout << j->getType() << " noise: ";
	j->makeSound();
	delete j;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	std::cout << meta->getType() << " noise: ";
	meta->makeSound();
	delete meta;
	std::cout << std::endl;

	const	WrongAnimal* wrong = new WrongCat();
	std::cout << wrong->getType() << " noise: ";
	wrong->makeSound();
	delete wrong;
	std::cout << std::endl;

	const	WrongCat* wrong2 = new WrongCat();
	std::cout << wrong2->getType() << " noise: ";
	wrong2->makeSound();
	delete wrong2;
	std::cout << std::endl;
	
	return (0);
}