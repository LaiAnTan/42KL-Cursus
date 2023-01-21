#include "Zombie.hpp"

/*
When a variable is created, it is allocated on the stack.

Allocating on the stack is faster than heap allocation because
memory is allocated and deallocated more quickly on the stack.

However, stack size is limited and the program may fail or crash if too many
variables are allocated on the stack.

This variable "randomChump" will be destructed and freed once the function
exits.
*/

void	randomChump(string name)
{
	Zombie randomChump;
	randomChump.setName(name);
	randomChump.announce();
}