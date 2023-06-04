#ifndef MY_AWESOME_PHONE_BOOK_HPP

#define MY_AWESOME_PHONE_BOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class Contact
{
	public:
		std::string		getFirstName(void);
		std::string		getLastName(void);
		std::string		getNickname(void);
		std::string		getDarkestSecret(void);
		std::string		getPhoneNumber(void);
		void			setContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber);
		
	private:
		std::string first, last, nick, secret, num;
};

class PhoneBook
{
	public:
		void		cmdADD(void);
		void		cmdSEARCH(void);
		void		setIndex(int i);
		void		displayContactTable(void);
		void		displayContact(int i);
		void		addContact(std::string FirstName, std::string LastName, std::string Nickname, std::string DarkestSecret, std::string PhoneNumber);	
	private:
		int		index;
		Contact	contact[8];
};

#endif