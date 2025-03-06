#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp() {
    std::time_t t = std::time(NULL);
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

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Account::~Account(){}

int Account::checkAmount()const
{
    return (_amount);
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    int i = 0;
    std::cout << "index:" << i++ << ";"
                  << "amount:" << getTotalAmount() << ";"
                  << "deposits:" << getNbDeposits() << ";"
                  << "withdrawals:" << getNbWithdrawals() << std::endl;

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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused";
        std::cout << std::endl;
        return (false);
    }
    std::cout << std::endl;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    return (true);
}

void    Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << _totalAmount << ";" << "deposits:"
              << _totalNbDeposits << ";" << "withdrawal:"
              << _totalNbWithdrawals << ";" <<std::endl;
}
