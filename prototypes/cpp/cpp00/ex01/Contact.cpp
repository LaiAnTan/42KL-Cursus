#include "MyAwesomePhoneBook.hpp"

std::string	Contact::getFirstName()
{
	return (first);
}

std::string	Contact::getLastName()
{
	return (last);
}

std::string	Contact::getNickname()
{
	return (nick);
}

std::string	Contact::getDarkestSecret()
{
	return (secret);
}

std::string	Contact::getPhoneNumber()
{
	return (num);
}

void		Contact::setContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber)
{
	this->first = FirstName;
	this->last = LastName;
	this->nick = Nickname;
	this->secret = DarkestSecret;
	this->num = PhoneNumber;
}