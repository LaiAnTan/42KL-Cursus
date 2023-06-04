#include "Span.hpp"

int main(void)
{
	Span	*span = new Span(5);


	for (int i = 0; i < 5; i++)
		span->addNumber(i);

	delete span;
}