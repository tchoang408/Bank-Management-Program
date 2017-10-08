//
//  PersonalAccount.cpp
//  Bank_management_system
//
//  Created by Goat on 8/18/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#include "PersonalAccount.hpp"
#include "Checking_Account.hpp"
#include "Saving_Account.hpp"
#include "Debit_card.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;


PersonalAccount::PersonalAccount()
{
	unsigned seed = time(0);
	srand(seed);
}
PersonalAccount::PersonalAccount(string name, double S)
{
	accountName = name;
	SSN = S;
}
void PersonalAccount::createNewChecking(double acc, double rout, double initialBal)
{
	Checking_Account *testAccount = new Checking_Account(acc,rout, initialBal);
	accountPtr = testAccount;
	int debitNum1 =  (rand() % (99999999 - 10000000 + 1)) + 10000000;
	int debitNum2 =  (rand() % (99999999 - 10000000 + 1)) + 10000000;
	int securityCode =  (rand() % (999 - 100 + 1)) + 100;
	string temp = to_string(debitNum1);
	string temp2 = to_string(debitNum2);
	temp += temp2;
	double debitNum = stod(temp);
	time_t t = time(0);
	struct tm *now = localtime( & t );
	string month = to_string(now->tm_mon + 1);
	string year = to_string(now->tm_year + 1900 + 5);
	string exp = month + "/" + year;
	createNewDebitCard(debitNum, exp, securityCode);
	
}
void PersonalAccount::createNewSaving(double acc, double rout, double initialBal)
{
	Saving_Account *savingAccount = new Saving_Account(acc,rout,initialBal);
	savingPtr = savingAccount;
	
}
void PersonalAccount::createNewDebitCard(double debitNum, string exp, int sec){
	Debit_card *newDebit = new Debit_card(debitNum, exp , sec, accountName);
	newDebit->setCheckAccount(accountPtr);
	debitPtr = newDebit;
	sampleStatement();
}
void PersonalAccount::sampleStatement(){
	debitPtr->debitPurchased("Target.Panty", "10/17", 23.99);
	debitPtr->debitPurchased("Target.Socks", "10/17", 12.99);
	debitPtr->debitPurchased("Walmart.TV HD32", "14/17", 400);
	debitPtr->debitPurchased("Dave N buster", "15/17", 49.29);
	
	
	
}
