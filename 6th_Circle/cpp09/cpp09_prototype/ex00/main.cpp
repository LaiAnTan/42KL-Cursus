#include "BitcoinExchange.hpp"

#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

int	parseRates(BitcoinExchange &btc)
{
	std::string		date;
	std::string		value;
	std::string		line;

	std::fstream	data;

	data.open("data.csv", std::fstream::in);
	if (!data.is_open())
	{
		std::cerr << "Error: File could not be opened" << endl;
		return (-1);
	}
	std::getline(data, line);
	while (std::getline(data, line))
	{
		date = line.substr(0, 10);
		value = line.substr(line.rfind(',') + 1);
		if (isValidDate(date) 
			&& isValidRate(value))
			btc.addRate(date, std::strtof(value.c_str(), NULL));
	}
	data.close();
	return (0);
}

int	parseInput(BitcoinExchange &btc, char *filename)
{
	float	price;

	std::string		date;
	std::string		value;
	std::string		line;

	std::fstream	input;

	input.open(filename, std::fstream::in);
	if (!input.is_open())
	{
		std::cerr << "Error: File could not be opened" << endl;
		return (-1);
	}
	std::getline(input, line);
	while (std::getline(input, line))
	{
		date = line.substr(0, 10);
		try
		{
			value = line.substr(line.rfind('|') + 1);
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Error: No amount" << endl;
			continue ;
		}
		if (isValidDate(date) 
			&& isValidAmount(value))
		{
			price = btc.calculatePrice(date, std::strtof(value.c_str(), NULL));
			cout << date << " => " << value << " = " << price << endl;
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	BitcoinExchange	btc;

	if (argc != 2)
	{
		std::cerr << "Error: Wrong number of arguments" << endl;
		return (-1);
	}
	if (parseRates(btc) == -1 || parseInput(btc, argv[1]))
		return (-1);
	return (0);
}
