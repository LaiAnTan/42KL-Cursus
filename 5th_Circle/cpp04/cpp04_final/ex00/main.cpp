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
	const	Animal* alpha = new Animal();
	const	Animal* dog = new Dog();
	const	Animal* cat = new Cat();

	const	WrongAnimal* beta = new WrongAnimal();
	const	WrongAnimal* wrongcat = new WrongCat();
	
	/* Animal, Dog, Cat Tests */
	cout << "Animal, Dog, Cat Tests" << endl;
	cout << alpha->getType() << endl;
	alpha->makeSound();

	cout << dog->getType() << endl;
	dog->makeSound();

	cout << cat->getType() << endl;
	cat->makeSound();

	/* WrongAnimal, WrongCat Tests */
	cout << "WrongAnimal, WrongCat Tests" << endl;
	cout << beta->getType() << endl;
	beta->makeSound();

	cout << wrongcat->getType() << endl;
	wrongcat->makeSound();

	return (0);
}