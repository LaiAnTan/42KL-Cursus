#include "BitcoinExchange.hpp"

#include <map>
#include <string>
#include <utility>
#include <iostream>
#include <cstdlib>
#include <iterator>

using std::cout;
using std::endl;

BitcoinExchange::BitcoinExchange()
{
	cout << "BitcoinExchange: Constructor called" << endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copyfrom)
{
	cout << "BitcoinExchange: Copy constructor called" << endl;
	*this = copyfrom;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &copyfrom)
{
	if (this == &copyfrom)
		return (*this);
	this->exchangeRates = copyfrom.exchangeRates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	cout << "BitcoinExchange: Destructor called" << endl;
}

void	BitcoinExchange::addRate(std::string date, float rate)
{
	exchangeRates.insert(std::pair<std::string, float>(date, rate));
}

// .erase number of elements removed (0 or 1)
void	BitcoinExchange::removeRate(std::string date)
{
	exchangeRates.erase(date);
}

// if not found, returns past-the-end iterator, end()
std::map<std::string, float>::iterator	BitcoinExchange::getLowerBoundRate(std::string date)
{
	return (exchangeRates.lower_bound(date));
}

float	BitcoinExchange::calculatePrice(std::string date, float amount)
{
	// reverse iterator inits 1 element behind normal iterator
	std::map<std::string, float>::reverse_iterator	pair(getLowerBoundRate(date));

	if (pair == exchangeRates.rend())
	{
		std::cerr << "Error: Date out of range => " << date << endl;
		return (-1);
	}
	
	return (pair->second * amount);
}

bool	isValidDate(std::string &date)
{
	// valid date = 2011-12-31
	int	year;
	int	month;
	int	day;

	try
	{
		year = std::strtol(date.substr(0, 4).c_str(), NULL, 10);
		month = std::strtol(date.substr(5, 2).c_str(), NULL, 10);
		day = std::strtol(date.substr(8, 2).c_str(), NULL, 10);
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << "Error: Bad input => " << date << endl;
		return (false);
	}
	if (year >= 2009 
		&& (month >= 1 && month <= 12) 
		&& (day >= 1 && day <= 31) 
		&& (date[4] == '-')
		&& (date[7] == '-')
	)
		return (true);
	std::cerr << "Error: Bad input => " << date << endl;
	return (false);
}

bool	isValidRate(std::string &rate)
{
	float	num;

	try
	{
		num = std::strtof(rate.c_str(), NULL);
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Error: Out of range => " << rate << endl;
		return (false);
	}
	if (num < 0)
	{
		std::cerr << "Error: Not a positive number => " << num << endl;
		return (false);
	}
	return (true);
}

bool	isValidAmount(std::string &amount)
{
	float	num;

	try
	{
		num = std::strtof(amount.c_str(), NULL);
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << "Error: Out of range => " << amount << endl;
		return (false);
	}
	if (num < 0)
	{
		std::cerr << "Error: Not a positive number => " << num << endl;
		return (false);
	}
	if (num > 1000)
	{
		std::cerr << "Error: Too large a number => " << num << endl;
		return (false);
	}
	return (true);
}