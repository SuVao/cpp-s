#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp()
{
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);

    std::cout << "[" << (now->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
              << std::setfill('0') << std::setw(2) << now->tm_mday << "_"
              << std::setfill('0') << std::setw(2) << now->tm_hour
              << std::setfill('0') << std::setw(2) << now->tm_min
              << std::setfill('0') << std::setw(2) << now->tm_sec << "] ";
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    _nbDeposits++;
	std::cout << "Index:" << _accountIndex << ";"
			  << "p_amount:" << checkAmount() << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << checkAmount() + deposit << ";"
			  << "nb_deposits:" << _nbDeposits << std::endl;
    _amount += deposit;
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

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::checkAmount()const
{
    return (_amount);
}

void    Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
                  << "amount:" << checkAmount() << ";"
                  << "deposits:" << _nbDeposits << ";"
                  << "withdrawals:" << _nbWithdrawals << std::endl;

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
    _nbWithdrawals++;
    std::cout << ";amount:" << _amount - withdrawal << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
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
