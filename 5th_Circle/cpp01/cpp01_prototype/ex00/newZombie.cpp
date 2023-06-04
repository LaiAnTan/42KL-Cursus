#include "Zombie.hpp"

/*
When a variable (primarily objects) is dynamically allocated memory 
using the new keyword, the memory is allocated on the heap.

The constructor of the object is also called to initialize the object.

The object can be returned and use outside of the scope of the function.

When the object is no longer used, the memory must be freed
using the delete keyword.

*/

Zombie*	newZombie(string name)
{
	Zombie* newZombie = new Zombie();
	newZombie->setName(name);
	return (newZombie);
}