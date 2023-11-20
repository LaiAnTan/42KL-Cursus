#include "functions.hpp"

Base	*generate(void)
{
	int		num;

	srand((unsigned) time(NULL));
	num = rand() % 3;
	
	switch (num)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != 0)
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p) != 0)
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p) != 0)
		cout << "C" << endl;
	else
		cout << "Not a subclass of class base" << endl;

}

void	identify(Base &p)
{
	try
	{
		Base	&sub = dynamic_cast<A&>(p);
		(void) sub;
		cout << "A" << endl;
		return ;
	}
	catch (const exception &err)
	{
		try
		{
			Base	&sub = dynamic_cast<B&>(p);
			(void) sub;
			cout << "B" << endl;
			return ;
		}
		catch (const exception &err)
		{
			try
			{
				Base	&sub = dynamic_cast<C&>(p);
				(void) sub;
				cout << "C" << endl;
				return ;
			}
			catch(const exception &err)
			{
				cout << "Not a subclass of class base" << endl;
			}
			
		}
	}
}

// note: bad_cast exception is in typeinfo header which is forbidden