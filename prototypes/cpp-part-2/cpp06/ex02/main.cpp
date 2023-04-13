#include "Classes.hpp"
#include "functions.hpp"

int main(void)
{
	Base	*r = generate();

	Base	**r_ref = &r;

	cout << "Actual type of object identified with pointers: ";
	identify(r);

	cout << "Actual type of object identified with reference: ";
	identify(**r_ref);

	delete r;
}