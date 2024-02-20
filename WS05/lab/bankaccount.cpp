/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char* name, bool checking)
	{
		m_userName[0] = '\0';		// Empty string implies is account is not open 
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char* name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// ADD: Type Conversion, Unary & Binary Operators; + Additional Methods
	bankAccount::operator bool() const {
		return isOpen();
	}

	bankAccount::operator double() const {
		return m_funds;
	}

	bankAccount& bankAccount::operator++() {
		if (isOpen() && m_funds > 0) {
			m_funds += (m_checking) ? ((m_funds * CHQ_INTEREST)/100) : ((m_funds * SAV_INTEREST)/100);
		}
		return *this;
	}

	bankAccount& bankAccount::operator--() {
		if (isOpen()) {
			m_funds -= (m_checking) ? m_monthlyTransactions * CHQ_FEE : m_monthlyTransactions * SAV_FEE;
		}
		return *this;
	}

	bool bankAccount::operator+= (double value) {
		if (isOpen()) {
			m_funds += value;
			m_monthlyTransactions++;

			cout << "Deposit $";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << value;
			cout.unsetf(ios::fixed);
			cout << " for " << m_userName << endl;
			return true;
		}
		else {
			return false;
		}
	}

	bool bankAccount::operator-= (double value) {
		if (isOpen()) {
			m_funds -= value;
			m_monthlyTransactions++;

			cout << "Withdraw $";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << value;
			cout.unsetf(ios::fixed);
			cout << " for " << m_userName << endl;
			return true;
		}
		else {
			return false;
		}
	}

	bool bankAccount::operator== (const bankAccount& rhs) const {
		return (strcmp(m_userName, rhs.m_userName) == 0 && m_funds == rhs.m_funds && m_checking == rhs.m_checking);
	}

	bool bankAccount::operator> (double value) const {
		if (isOpen()) {
			return (m_funds > value);
		}
		else {
			return false;
		}
	}

	bool bankAccount::operator<= (double value) const {
		if (isOpen()) {
			return (m_funds <= value);
		}
		else {
			return false;
		}
	}

	bool bankAccount::operator<< (bankAccount& rhs) {
		if (isOpen() && rhs.isOpen() && rhs.m_funds > 0) {
			cout << "Transfer $";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << rhs.m_funds;
			cout.unsetf(ios::fixed);
			cout << " from " << rhs.m_userName << " to " << m_userName << endl;
			operator+=(rhs.m_funds);
			rhs.operator-=(rhs.m_funds);
			return true;
		}
		else {
			return false;
		}
	}

	void bankAccount::display(void) const {
		if (isOpen()) {
			cout << "Display Account -> User:";

			cout.setf(ios::right);
			cout.fill('-');
			cout.width(ACCT_MAXLEN_USER);
			cout << m_userName;
			cout.unsetf(ios::right);

			cout << " | ";
			if (m_checking) {
				cout << "Checking";
			}
			else {
				cout << " Savings";
			}

			cout << " | Balance: $  ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(6);
			cout.fill(' ');
			cout << m_funds;
			cout.unsetf(ios::fixed);

			cout << " | Transactions:";
			cout.precision(0);
			cout.width(3);
			cout.fill('0');
			cout << m_monthlyTransactions << endl;

		}
		else {
			cout << "Display Account -> User:";
			cout.setf(ios::right);
			cout.fill('-');
			cout.width(ACCT_MAXLEN_USER);
			cout << " NOT OPEN" << endl;
			cout.unsetf(ios::right);
		}

	}
	// ADD: Global Helper Functions
	bool operator> (double lhs, const bankAccount& rhs) {
		if (static_cast<bool>(rhs)) {
			return lhs > static_cast<double>(rhs);
		}
		return false;
	}

	bool operator<= (double lhs, const bankAccount& rhs) {
		return !operator>(lhs, rhs);
	}
}