#ifndef CAT_HPP

#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

#include <string>

class Cat: public AAnimal
{
	public:
		Cat();
		Cat(const Cat &cat);
		Cat &operator = (const Cat &cat);
		~Cat();

		void	makeSound(void) const;

	private:
		Brain *brain;
};


#endif