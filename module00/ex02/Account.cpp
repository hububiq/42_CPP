/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgatarek <hgatarek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:44:29 by hgatarek          #+#    #+#             */
/*   Updated: 2025/11/12 15:40:19 by hgatarek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


/*   there is one shared copy of static in-class data members _totalAmount and _nbAccounts.
    it will be updated every time concstructor created one o 8 Account objects (class instances)   */
Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created" << std::endl;
    _totalAmount = _totalAmount + _amount;
    _nbAccounts++;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

/*  taking the raw time since epoch. time() returns the pointer to tm structure. 
it hold all info from broken-down time - representation separated into year, month, day, so on.  */
void    Account::_displayTimestamp( void )
{
   std::time_t since_last_epoch;
   
   since_last_epoch = std::time(NULL);

   std::cout << "[" << std::localtime(&since_last_epoch)->tm_year;
   std::cout << std::localtime(&since_last_epoch)->tm_mon;
   std::cout << std::localtime(&since_last_epoch)->tm_mday << "_";
   std::cout << std::localtime(&since_last_epoch)->tm_hour;
   std::cout << std::localtime(&since_last_epoch)->tm_min;
   std::cout << std::localtime(&since_last_epoch)->tm_sec;
   std::cout << "]";
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

