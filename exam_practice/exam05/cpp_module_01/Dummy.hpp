#include "ATarget.hpp"

class Dummy: public ATarget
{
	public:
		Dummy();
		~Dummy();
		ATarget* clone(void) const;

};