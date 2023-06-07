#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

using	std::cout;
using	std::endl;
using	std::string;

int main()
{
	// test 1 (singular animal)
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	// test 2

	Animal* animals[100];

	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();

	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 100; i++)
		delete animals[i];

	return 0;
}
