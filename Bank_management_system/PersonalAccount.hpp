//
//  PersonalAccount.hpp
//  Bank_management_system
//
//  Created by Goat on 8/18/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#ifndef PersonalAccount_hpp
#define PersonalAccount_hpp

#include "Checking_Account.hpp"
#include "Saving_Account.hpp"
#include "Debit_card.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

class PersonalAccount
{
	
private:
	string accountName;
	double SSN;
	Checking_Account *accountPtr;
	Debit_card *debitPtr;
	Saving_Account *savingPtr;
public:
	PersonalAccount();
	PersonalAccount(string, double);
	Checking_Account* getChecking(){return accountPtr;}
	Saving_Account* getSaving(){return savingPtr;}
	void createNewChecking(double, double, double);
	void createNewDebitCard(double, string, int);
	void createNewSaving(double, double, double);
	Debit_card getDebitCard(){return *debitPtr;}
	void sampleStatement();
	
	
	
};
#endif /* PersonalAccount_hpp */
