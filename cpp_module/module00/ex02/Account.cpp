#include "Account.hpp"
#include <iostream>
#include <ctime>

int		Account::getNbAccounts( void ) { return _nbAccounts; }
int		Account::getTotalAmount( void ) { return _totalAmount; }
int		Account::getNbDeposits( void ) { return _totalNbDeposits; }
int		Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }
int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" <<  _amount << ';';
	std::cout << "created" << std::endl;
	_totalAmount += _amount;
}

Account::~Account ( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" <<  _amount << ';';
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" <<  _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" <<  _amount << ';';
	std::cout << "deposit:" << deposit << ';';
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" <<  _amount << ';';
	_nbDeposits = 1;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	int	temp = _amount;
	temp -= withdrawal;
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" <<  _amount << ';';
	if (temp < 0){
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_amount = temp;
	_totalAmount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ';';
	std::cout << "amount:" <<  _amount << ';';
	_nbWithdrawals = 1;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_totalNbWithdrawals++;
	return true;
}

void	Account::_displayTimestamp( void ) {
	std::time_t now = std::time(nullptr);
	std::tm *locale_time = std::localtime(&now);
	char	buf[19];

	strftime(buf, 19, "[%Y%m%d_%H%M%S] ", locale_time);
	std::cout << buf;
}

