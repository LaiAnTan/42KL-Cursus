#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
	public:
		~Zombie(void);
		void	setName(string name);
		void	announce(void);
	private:
		string	name;
};

void	randomChump(string name);
Zombie*	newZombie(string name);

#endif