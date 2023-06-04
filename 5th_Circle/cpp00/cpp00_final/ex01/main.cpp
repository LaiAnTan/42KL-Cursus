#include "MyAwesomePhoneBook.hpp"

int	main()
{
	std::string	cmd;
	PhoneBook	phonebook;

	phonebook.setIndex(0);
	std::cout << "--commands--\n" << "1. ADD\n" << "2. SEARCH\n" << "3. EXIT" << std::endl;
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, cmd);
		if (std::cin.fail())
		{
			std::cin.ignore();
			std::cin.clear();
		}
		if (cmd == "ADD")
			phonebook.cmdADD();
		else if (cmd == "SEARCH")
			phonebook.cmdSEARCH();
		else if (cmd == "EXIT")
			return (0);
		else
			std::cout << "Invalid input" << std::endl;
	}
	return (0);
}