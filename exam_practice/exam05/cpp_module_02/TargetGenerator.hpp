#include "ATarget.hpp"

#include <string>
#include <map>

using std::string;
using std::map;

class TargetGenerator
{
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(string const &targetType);
		ATarget* createTarget(string const &targetType);

	private:
		map<string, ATarget*> store;
};