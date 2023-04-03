#ifndef AANIMAL_HPP

#define AANIMAL_HPP

#include <string>

using	std::string;

class AAnimal
{
	public:
		AAnimal &operator = (const AAnimal &animal);
		virtual			~AAnimal();
		string			getType(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		AAnimal();
		AAnimal(string type);
		AAnimal(const AAnimal &animal);

		string	type;
};

#endif