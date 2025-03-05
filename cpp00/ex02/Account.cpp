#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>

void	Account::_displayTimestamp() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900)
              << (now->tm_mon + 1) << now->tm_mday << "_"
              << now->tm_hour << now->tm_min << now->tm_sec << "] ";
}

void    Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

Account::Account(int initial_deposit){}

Account::~Account(){}

int Account::checkAmount()const
{
    return (_amount);
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << _totalAmount << ";" << "deposits:"
              << _totalNbDeposits << ";" << "withdrawal:"
              << _totalNbWithdrawals << ";" <<std::endl;
}

int Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal >= _amount)
        return (false);
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _amount -= withdrawal;
    return (true);
}
