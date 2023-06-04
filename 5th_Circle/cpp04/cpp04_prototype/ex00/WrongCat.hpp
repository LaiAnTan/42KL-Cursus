#ifndef WrongCat_HPP

#define WrongCat_HPP

#include "WrongAnimal.hpp"

#include <string>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &WrongCat);
		WrongCat &operator = (const WrongCat &WrongCat);
		~WrongCat();

		void	makeSound(void) const;
};


#endif