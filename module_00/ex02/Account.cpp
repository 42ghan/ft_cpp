/**
 * @file Account.cpp
 * @author ghan (ghan@student.42seoul.kr)
 * @brief definitions & initializations of Account class members
 * @date 2022-02-24
 */

#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>

// initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// private constructor without any parameter
Account::Account(void) {
  this->_accountIndex = _nbAccounts++;
  this->_amount = 0;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created\n";
};

// display current timestamp of local timezone in [YYYYMMDD_hhmmss] format
void Account::_displayTimestamp(void) {
  const time_t now = time(NULL);
  struct tm *time_s = localtime(&now);

  std::cout << '[' << time_s->tm_year + 1900 << std::setw(2)
            << std::setfill('0') << time_s->tm_mon + 1 << std::setw(2)
            << std::setfill('0') << time_s->tm_mday << '_' << std::setw(2)
            << std::setfill('0') << time_s->tm_hour << std::setw(2)
            << std::setfill('0') << time_s->tm_min << std::setw(2)
            << std::setfill('0') << time_s->tm_sec << ']';
}

// public constructor with initial deposit as a parameter
Account::Account(int initial_deposit) {
  this->_accountIndex = _nbAccounts++;
  this->_amount = initial_deposit;
  _totalAmount += initial_deposit;
  this->_nbDeposits = 0;
  this->_nbWithdrawals = 0;

  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";created\n";
}

// public destructor
Account::~Account(void) {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed\n";
}

// Account class getter member functions;
int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

// display information of existing accounts
void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

// make a deposit
void Account::makeDeposit(int deposit) {
  const int p_amount = this->checkAmount();

  this->_amount += deposit;
  _totalAmount += deposit;
  this->_nbDeposits++;
  _totalNbDeposits++;
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
            << ";deposit:" << deposit << ";amount:" << this->_amount
            << ";nb_deposits:" << this->_nbDeposits << '\n';
}

// make a withdrawal
bool Account::makeWithdrawal(int withdrawal) {
  const int p_amount = this->checkAmount();
  const bool result = p_amount >= withdrawal;

  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
            << ";withdrawal:";
  if (!result)
    std::cout << "refused\n";
  else {
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << '\n';
  }
  return (result);
}

// READONLY!! check current amount present in an account
int Account::checkAmount(void) const { return this->_amount; }

// READONLY!! display status of each account
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << " index:" << this->_accountIndex
            << ";amount:" << this->checkAmount()
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << '\n';
}