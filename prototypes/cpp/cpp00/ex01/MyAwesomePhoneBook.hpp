#ifndef MY_AWESOME_PHONE_BOOK_HPP

#define MY_AWESOME_PHONE_BOOK_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		std::string		getFirstName();
		std::string		getLastName();
		std::string		getNickname();
		std::string		getDarkestSecret();
		std::string		getPhoneNumber();
		void			setContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber);
		
	private:
		std::string first, last, nick, secret, num;
};

class PhoneBook
{
	public:
		void		AddContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber);	
	private:
		int		index;
		Contact	Contact[8];
};

#endif