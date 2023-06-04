#include "Serializer.hpp"

Serializer::Serializer()
{
	cout << "Serializer: Default Constructor called" << endl;
}

Serializer::Serializer(const Serializer &serializer)
{
	cout << "Serializer: Copy constructor called" << endl;
	*this = serializer;
}

Serializer &Serializer::operator = (const Serializer &serializer)
{
	cout << "Serializer: Copy assignment operator called" << endl;
	if (this == &serializer)
		return (*this);
	(void) serializer;
	return (*this);
}

Serializer::~Serializer()
{
	cout << "Serializer: Destructor called" << endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}