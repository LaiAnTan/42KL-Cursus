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

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

Account::Account( int initial_deposit )
{
	_accountIndex = 0;
	_accountIndex += _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbAccounts += 1;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";deposits:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (withdrawal <= _amount)
	{
		std::cout << withdrawal;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
			_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}

int	Account::checkAmount( void ) const 
{
	return (_amount);
}

void	Account::displayStatus( void ) const 
{
	_displayTimestamp();
	std::cout  << "index:" << _accountIndex;
	std::cout  << ";amount:" << _amount;
	std::cout  << ";deposits:" << _nbDeposits;
	std::cout  << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t	curr_time = std::time(0);
	std::tm		*time = std::localtime(&curr_time);

	std::cout << "[" << (time->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_mday) << "_";
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_hour);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_min);
	std::cout << std::setfill('0') << std::setw(2) << (time->tm_sec) << "] ";
}

