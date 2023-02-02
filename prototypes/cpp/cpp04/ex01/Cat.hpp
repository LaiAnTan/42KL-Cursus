#ifndef CAT_HPP

#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#include <string>

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat &cat);
		Cat &operator = (const Cat &cat);
		~Cat();

		void	makeSound(void) const;
	
	private:
		Brain	*brain;
};


#endif