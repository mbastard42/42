#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal * zoo[6];

	for (int i = 0; i < 3; i++)
		zoo[i] = new Dog;
	for (int i = 3; i < 6; i++)
		zoo[i] = new Cat;
	for (int i = 0; i < 6; i++)
		delete zoo[i];
	return (0);
}