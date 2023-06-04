#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data	dataA;
	
	cout << "Original address of data structure: " << &dataA << endl;

	cout << "Address of data structure after serialization and deserialization: " << Serializer::deserialize(Serializer::serialize(&dataA)) << endl;


}