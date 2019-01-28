#include "Account.class.hpp"
#include <iostream>


int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;
int			Account::getNbAccounts(void) { return _nbAccounts; }
int			Account::getTotalAmount(void) { return _totalAmount; }
int			Account::getNbDeposits(void) { return _totalNbDeposits; }
int			Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }



void		Account::displayAccountsInfos( void ) {              
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts	<< ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

Account::Account(int initial_deposit) :	_accountIndex(getNbAccounts()),	_amount(initial_deposit),_nbDeposits(0), _nbWithdrawals(0) {
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount	<< ";created" << std::endl;
}


// CREATE DISPLAY TIME TEMP:
void		Account::_displayTimestamp(void)
{
	std::cout << "[TOTO] ";
}


Account::~Account(void) {
	_nbAccounts--;
}

void	Account::makeDeposit( int deposit ){

}

bool	Account::makeWithdrawal( int withdrawal ){

	Account::_displayTimestamp();
	if (withdrawal > this->_amount)	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
		<< ";withdrawal:refused" << std::endl;
		return false;
	}

	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount + withdrawal
		<< ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

int		Account::checkAmount( void ) const{
	return _amount;
}

void	Account::displayStatus( void ) const {

		// display le Time stamp	
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}