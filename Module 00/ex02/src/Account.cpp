/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:17:22 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/13 22:09:01 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();

	std::cout 
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< initial_deposit
		<<";"
		<< "created"
		<< std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();

	this->_nbAccounts--;

	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "amount:"
		<< this->_amount
		<< ";"
		<< "closed"
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	now;
	tm		*ltm;

	now = time(0);
	ltm = localtime(&now);

	std::cout
		<< "[" 
		<< 1900 + ltm->tm_year
		<< 1 + ltm->tm_mon
		<< ltm->tm_mday
		<< "_"
		<< ltm->tm_hour
		<< ltm->tm_min
		<< ltm->tm_sec
		<< "] ";
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();

	std::cout
		<< "accounts:"
		<< Account::_nbAccounts
		<< ";"
		<< "total:"
		<< Account::_totalAmount
		<< ";"
		<< "deposits:"
		<< Account::_totalNbDeposits
		<< ";"
		<< "withdrawals:"
		<< Account::_totalNbWithdrawals
		<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();

	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";"
		<< "p_amount:"
		<< this->_amount
		<< ";"
		<< "deposit:"
		<< deposit
		<< ";";

	this->_amount += deposit;
	Account::_totalAmount += deposit;

	
	std::cout << "amount:" << this->_amount << ";";
	
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" <<  this->_amount << ";";

	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::checkAmount(void) const
{
	return (this->_amount > 0);
}
