#include "iter.hpp"

template <typename T>
void	printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void	to_G(char &c)
{
	c = 'G';
}

void	to_69(int &i)
{
	i = 69;
}

void	appendSus(string &str)
{
	str.append("_sus");
}

int main(void)
{
	char	charArray[] = {'a', 'b', 'c', 'd', 'e'};
	int		intArray[] = {0, 100, 42, -42, 69};
	string	strArray[] = {"hehe", "amogus", "ur mom", "Lorem ipsum dolor sit amet", ""};

	cout << "Before iter:" << endl;
	printArray(charArray, 5);
	printArray(intArray, 5);
	printArray(strArray, 5);

	iter(charArray, 5, to_G);
	iter(intArray, 5, to_69);
	iter(strArray, 5, appendSus);

	cout << "After iter:" << endl;
	printArray(charArray, 5);
	printArray(intArray, 5);
	printArray(strArray, 5);

	return (0);
}