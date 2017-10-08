//
//  Checking_Account.hpp
//  Bank_management_system
//
//  Created by Goat on 8/4/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#ifndef Checking_Account_hpp
#define Checking_Account_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Checking_Account
{
private:
	struct statement{
		string date;
		string description;
		double amount;
		double runningBalance;
	};
	double balance;
	double routingNumber;
	double accountNumber;
	list<statement> checkingStatement;
public:
	Checking_Account();
	Checking_Account(double acc, double rout, double bal):
	accountNumber(acc), routingNumber(rout),balance(bal){}
	~Checking_Account(){}
	double getAccountNum(){return accountNumber;}	
	void checkBalance();
	void savingBlance();
	void withdraw(double);
	void deposit(double);
	struct statement getStatement(){statement s;return s;}
	double getBalance(){return balance;}
	void setBalance(double price){balance -= price;}
	void addStatement(string, string, double);
	
};
#endif /* Checking_Account_hpp */
