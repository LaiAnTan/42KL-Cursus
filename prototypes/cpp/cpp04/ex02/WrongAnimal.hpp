#ifndef WRONG_ANIMAL_HPP

#define WRONG_ANIMAL_HPP

#include <string>

using	std::string;

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(string type);
		WrongAnimal(const WrongAnimal &wrong_animal);
		WrongAnimal &operator = (const WrongAnimal &wrong_animal);
		~WrongAnimal();

		string			getType(void) const;
		void			makeSound(void) const;

	protected:
		string	type;
};

#endif