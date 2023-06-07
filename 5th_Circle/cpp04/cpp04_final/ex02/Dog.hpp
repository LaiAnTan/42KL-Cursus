#ifndef DOG_HPP

#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	public:
		Dog();
		Dog(const Dog &dog);
		Dog	&operator = (const Dog &dog);
		~Dog();

		void	makeSound(void) const;

	private:
		Brain *brain;
};

#endif
