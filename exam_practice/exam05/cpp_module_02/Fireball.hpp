#include "ASpell.hpp"

class Fireball: public ASpell
{
	public:
		Fireball();
		~Fireball();
		ASpell* clone(void) const;
};