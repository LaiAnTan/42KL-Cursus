#include "Span.hpp"

using std::cout;
using std::endl;

Span::Span(unsigned int n): n(n)
{
	cout << "Span: Constructor called" << endl;
	this->container.reserve(n);
}

Span::Span(const Span &span)
{
	cout << "Span: Copy constructor called" << endl;
	*this = span;
}

Span &Span::operator = (const Span &span)
{
	cout << "Span: Copy assignment operator called" << endl;
	if (this == &span)
		return (*this);
	this->n = span.n;
	this->container = span.container;
	return (*this);
}

Span::~Span()
{
	cout << "Span: Destructor called" << endl;
}

void	Span::addNumber(int num)
{
	if (container.size() >= n)
		throw (Span::SpanFullException());
	container.push_back(num);
}

void	Span::addNumbers(int *intArray, unsigned int size)
{
	if (container.size() >= n || size > n || (size + container.size() > n))
		throw (Span::SpanFullException());
	container.insert(container.end(), intArray, intArray + size);
}

int	Span::getValue(unsigned int index) const
{
	if (index >= n)
		throw (Span::SpanIndexOutOfBoundsException());
	return (container.at(index));
}

int	Span::getSize(void) const
{
	return (n);
}

unsigned int	absDifference(int a, int b)
{
	if (a > b)
		return ((unsigned int) a - (unsigned int) b);
	else
		return ((unsigned int) b - (unsigned int) a);
}

// can use both transform or adjacent_difference
// transform leaves last element unchanged
// adjacent_difference leaves first element unchanged
unsigned int	Span::shortestSpan()
{
	long int	arr[container.size()];

	if (container.size() <= 1)
		throw (Span::SpanNotFoundException());

	std::partial_sort_copy(container.begin(), container.end(), arr, arr + container.size());
	std::adjacent_difference(arr, arr + container.size(), arr, absDifference);
	return (*std::min_element(arr + 1, arr + container.size()));
}

unsigned int	Span::longestSpan()
{
	if (container.size() <= 1)
		throw (Span::SpanNotFoundException());

	return (abs(*std::max_element(container.begin(), container.end()) - *std::min_element(container.begin(), container.end())));
}

const char* Span::SpanFullException::what() const throw()
{
	return ("SpanFullException: Span container is full");
}

const char* Span::SpanNotFoundException::what() const throw()
{
	return ("SpanNotFoundException: Span not found");
}

const char* Span::SpanIndexOutOfBoundsException::what() const throw()
{
	return ("SpanNotFoundException: Span index out of bounds");
}

ostream &operator << (ostream &outs, const Span &span)
{
	int size = span.getSize();
	outs << "[ ";
	for (int i = 0; i < size; ++i)
		outs << span.getValue(i) << ' ';
	outs << "]";
	return (outs);
}