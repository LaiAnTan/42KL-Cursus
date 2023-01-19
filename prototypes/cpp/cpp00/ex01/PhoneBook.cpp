#include "MyAwesomePhoneBook.hpp"

void		PhoneBook::AddContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber)
{
	if (this->index == 8)
		this->index = 0;
	this->Contact[this->index].setContact(FirstName, LastName, Nickname, DarkestSecret, PhoneNumber);
	this->index += 1;
}