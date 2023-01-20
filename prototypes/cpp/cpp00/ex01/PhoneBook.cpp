#include "MyAwesomePhoneBook.hpp"

void		PhoneBook::setIndex(int i)
{
	this->index = i;
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
	std::cout << "Contact added to index " << this->index << std::endl;
	setIndex(this->index++);
}

std::string	trunc_str(std::string str)
{
	if (str.length() > 9)
		return (str.substr(0, 8).append("."));
	return (str);
}

void		PhoneBook::displayContact(int i)
{
	std::cout << "|" << std::setw(10) << i; 
	std::cout << "|" << std::setw(10) << trunc_str(this->contact[i].getFirstName());
	std::cout << "|" << std::setw(10) << trunc_str(this->contact[i].getLastName());
	std::cout << "|" << std::setw(10) << trunc_str(this->contact[i].getNickname());
	std::cout << "|" << std::endl;
}