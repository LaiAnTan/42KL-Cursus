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
	if (container.size() > n)
		throw (Span::SpanFullException());
	container.push_back(num);
}

unsigned int	Span::shortestSpan()
{
	if (container.size() <= 1)
		throw (Span::SpanNotFoundException());

	std::vector<int>::iterator	iterBegin = container.begin();
	std::vector<int>::iterator	iterEnd = container.end();

	return ();
}

unsigned int	Span::longestSpan()
{
	if (container.size() <= 1)
		throw (Span::SpanNotFoundException());

	std::vector<int>::iterator	iterBegin = container.begin();
	std::vector<int>::iterator	iterEnd = container.end();
	std::vector<int>::iterator	min = std::min_element(iterBegin, iterEnd);
	std::vector<int>::iterator	max = std::max_element(iterBegin, iterEnd);

	return (*max - *min);
}

const char* Span::SpanFullException::what() const throw()
{
	return ("SpanFullException: Span container is full");
}

const char* Span::SpanNotFoundException::what() const throw()
{
	return ("SpanNotFoundException: Span not found");
}