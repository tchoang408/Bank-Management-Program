//
//  Bank_Of_America.hpp
//  Bank_management_system
//
//  Created by Goat on 8/2/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#ifndef Bank_Of_America_hpp
#define Bank_Of_America_hpp

#include "Checking_Account.hpp"
#include "PersonalAccount.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

using namespace std;
//branch number: 2442
//employee ID: 12340

class Bank_Of_America
{
private:
	string branchNumber; // brach code consisted of 4 digit number
	string employeeIDNumber;
	vector<vector<string>> branchInfor;
	list<Checking_Account> customerAccount;
	list<PersonalAccount> privateAccount;
public:
	Bank_Of_America();
	~Bank_Of_America();
	void menu(PersonalAccount);
	void employeeMenu();
	void initializedBranch();
	void createSampleAccount();
	void checkCustomerAccount();
	void createNewDebitCard(double,string,int,string);
	void createNewPersonalAccount();
	list<PersonalAccount> getPersonalAccount(){return privateAccount;}
	
	
	
};




#endif /* Bank_Of_America_hpp */
