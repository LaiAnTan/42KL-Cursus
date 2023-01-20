#include "MyAwesomePhoneBook.hpp"

std::string	trunc_str(std::string str)
{
	if (str.length() > 9)
		return (str.substr(0, 8).append("."));
	return (str);
}

void	PhoneBook::cmdADD()
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

	addContact(first, last, nick ,secret, num);
	return ;
}

void	PhoneBook::cmdSEARCH()
{
	int	index;

	displayContactTable();
	std::cout << "Enter an index of the entry to be displayed: ";
	std::cin >> index;
	displayContact(index);
	return ;
}

void		PhoneBook::setIndex(int i)
{
	this->index = i;
}

void		PhoneBook::displayContactTable()
{
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1); 
		std::cout << "|" << std::setw(10) << trunc_str(this->contact[i].getFirstName());
		std::cout << "|" << std::setw(10) << trunc_str(this->contact[i].getLastName());
		std::cout << "|" << std::setw(10) << trunc_str(this->contact[i].getNickname());
		std::cout << "|" << std::endl;
	}
	return ;
}

void		PhoneBook::displayContact(int i)
{
	
	if (i < 1 || i > 9)
	{
		std::cout << "Index not found" << std::endl;
		return ;
	}
	i -= 1;
	std::cout << "First name: " << contact[i].getFirstName() << std::endl;
	std::cout << "Last name: " << contact[i].getLastName() << std::endl;
	std::cout << "Nickname: " << contact[i].getNickname() << std::endl;
	std::cout << "Darkest Secret: " << contact[i].getDarkestSecret() << std::endl;
	std::cout << "Phone Number: " << contact[i].getPhoneNumber() << std::endl;
	return ;
}

void		PhoneBook::addContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber)
{
	if (FirstName.empty() || LastName.empty() || Nickname.empty() || DarkestSecret.empty() || PhoneNumber.empty())
	{
		std::cout << "One or more fields empty, contact not saved" << std::endl;
		return ;
	}
	if (this->index == 8)
		this->index = 0;
	this->contact[this->index].setContact(FirstName, LastName, Nickname, DarkestSecret, PhoneNumber);
	std::cout << "Contact added to index " << this->index + 1 << std::endl;
	this->index += 1;
}