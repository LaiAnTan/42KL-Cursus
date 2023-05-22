#include "MyAwesomePhoneBook.hpp"

std::string	Contact::getFirstName(void)
{
	return (first);
}

std::string	Contact::getLastName(void)
{
	return (last);
}

std::string	Contact::getNickname(void)
{
	return (nick);
}

std::string	Contact::getDarkestSecret(void)
{
	return (secret);
}

std::string	Contact::getPhoneNumber(void)
{
	return (num);
}

void		Contact::setContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber)
{
	this->first.assign(FirstName);
	this->last.assign(LastName);
	this->nick.assign(Nickname);
	this->secret.assign(DarkestSecret);
	this->num.assign(PhoneNumber);
}