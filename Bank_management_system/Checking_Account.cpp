//
//  Checking_Account.cpp
//  Bank_management_system
//
//  Created by Goat on 8/4/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#include "Checking_Account.hpp"
#include "Debit_card.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include <ctime>
#include <cstdlib>
#include <ctime>
using namespace std;


Checking_Account::Checking_Account(){
	
}
void Checking_Account::checkBalance()
{
	cout << setprecision(8) <<"Account number: " << accountNumber << endl;
	cout << setprecision(8) <<"Routing number: " << routingNumber << endl;
	cout << "Balance: $" << balance <<endl;
	
	cout << setw(30) << "Statement" << endl << endl;
	cout << left << setw(8) << "Date"<< setw(40) << "Description" <<
			    setw(15) <<  "Amount" << setw(15) << "Remain Balance" << endl;
	for (auto x: checkingStatement){
		cout << left << setw(8) << x.date << setw(40) << x.description
				 << "$" << setw(14) <<  x.amount << "$" << setw(15) << x.runningBalance << endl;
	}

	
}

void Checking_Account::addStatement(string date, string description, double amount)
{
	statement newStatement;
	newStatement.date = date;
	newStatement.description = description;
	newStatement.amount = amount;
	newStatement.runningBalance = balance - amount;
	balance -= amount;
	checkingStatement.push_front(newStatement);
}

void Checking_Account::withdraw(double amount){
	time_t t = time(0);
	struct tm *now = localtime( & t );
	string month = to_string(now->tm_mon + 1);
	string year = to_string(now->tm_year + 1900);
	string year1;
	year1.append(year, 2, 2);
	string date = month + "/" + year1;

	addStatement(date, "Withraw Cash", amount);
}

void Checking_Account::deposit(double amount){
	time_t t = time(0);
	struct tm *now = localtime(&t);
	string month = to_string(now->tm_mon + 1);
	string year = to_string(now->tm_year + 1900);
	string year1;
	year1.append(year, 2, 2);
	string date = month + "/" + year1;
	amount *= -1;
	addStatement(date, "Deposit", amount);
	
	
	
	
	
	
	
	
	
	
}
