#ifndef WEAPON_HPP

#define WEAPON_HPP

#include <string>

using std::string;

class Weapon
{
	public:
		Weapon(string type);
		~Weapon();
		const string	getType();
		void			setType(string type);
	private:
		string	type;
};

#endif