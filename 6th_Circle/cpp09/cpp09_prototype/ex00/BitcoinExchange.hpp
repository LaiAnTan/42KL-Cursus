#pragma once

#ifndef BITCOINEXCHANGE_HPP

#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copyfrom);
		BitcoinExchange &operator = (const BitcoinExchange &copyfrom);
		~BitcoinExchange();

		void	addRate(std::string date, float rate);
		void	removeRate(std::string date);
		std::map<std::string, float>::iterator	getLowerBoundRate(std::string date);

		float	calculatePrice(std::string date, float amount);

	private:
		std::map<std::string, float>	exchangeRates;
};

bool	isValidDate(std::string &date);
bool	isValidRate(std::string &rate);
bool	isValidAmount(std::string &amount);

#endif