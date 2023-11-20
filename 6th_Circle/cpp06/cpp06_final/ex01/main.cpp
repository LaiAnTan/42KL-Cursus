#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data	dataA;

	dataA.ch = 'a';
	
	cout << "Original address of data structure: " << &dataA << endl;

	dataA = *Serializer::deserialize(Serializer::serialize(&dataA));

	cout << "Address of data structure after serialization and deserialization: " << &dataA << endl;

	cout << dataA.ch << endl;

}