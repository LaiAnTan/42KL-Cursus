#ifndef ANIMAL_HPP

#define ANIMAL_HPP

#include <string>

using	std::string;

class Animal
{
	public:
		Animal();
		Animal(string type);
		Animal(const Animal &animal);
		Animal &operator = (const Animal &animal);
		~Animal();

		string			getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		string	type;
};

#endif