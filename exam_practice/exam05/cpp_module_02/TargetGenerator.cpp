#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget *target)
{
	std::map<string, ATarget*>::iterator it = this->store.find(target->getType());

	if (it == this->store.end())
		this->store[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(string const &targetType)
{
	std::map<string, ATarget*>::iterator it = this->store.find(targetType);

	if (it != this->store.end())
		this->store.erase(it);
}

ATarget* TargetGenerator::createTarget(string const &targetType)
{
	std::map<string, ATarget*>::iterator it = this->store.find(targetType);

	if (it != this->store.end())
		return it->second;
	return NULL;
}
