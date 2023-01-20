#include "Account.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	displayAccountsInfos( void )
{
	std::cout << "test";
}

Account::Account( int initial_deposit )
{
	std::cout << "constructor called" << std::endl;
	_amount =0;
	_totalAmount = initial_deposit;

	this->_nbDeposits = 0;
	_totalNbDeposits = 0;

	_nbWithdrawals = 0;
	_totalNbWithdrawals = 0;

	_nbAccounts += 1;
	_accountIndex += 1;

}

Account::~Account( void )
{
	std::cout << "destructor called" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_nbDeposits = 1;
	_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		return (true);
	}
	else
		return (false);
	_nbWithdrawals += 1;
}

int	Account::checkAmount( void ) const 
{
	return (_amount);
}

void	Account::displayStatus( void ) const 
{
	std::cout << "hi" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	curr_time = std::time(0);
	std::tm		*time = std::localtime(&curr_time);

	std::cout << "[" << (time->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_mday) << "_";
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_hour);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_min);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_sec) << "]";
}

