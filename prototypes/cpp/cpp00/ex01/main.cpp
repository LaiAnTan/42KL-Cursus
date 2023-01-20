#include "MyAwesomePhoneBook.hpp"

static void	cmd_add(PhoneBook phonebook)
{
	std::string	first, last, nick, secret, num;

	std::cout << "Enter your information: " << std::endl;

	std::cout << "First name: ";
	std::getline(std::cin, first);

	std::cout << "Last name: ";
	std::getline(std::cin, last);

	std::cout << "Nickname: ";
	std::getline(std::cin, nick);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, secret);

	std::cout << "Phone Number: ";
	std::getline(std::cin, num);

	phonebook.addContact(first, last, nick ,secret, num);
	return ;
}

static void cmd_search(PhoneBook phonebook)
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;
	for (int i = 0; i < 8; i++)
		phonebook.displayContact(i);
}

int	main()
{
	std::string	cmd;
	PhoneBook	phonebook;

	phonebook.setIndex(0);
	std::cout 
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
			cmd_add(phonebook);
		else if (cmd == "SEARCH")
			cmd_search(phonebook);
		else if (cmd == "EXIT")
			return (0);
		else
			std::cout << "Invalid input" << std::endl;
	}
	return (0);
}