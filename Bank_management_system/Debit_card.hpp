//
//  Debit_card.hpp
//  Bank_management_system
//
//  Created by Goat on 8/4/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#ifndef Debit_card_hpp
#define Debit_card_hpp

#include <stdio.h>
#include <iostream>
#include "Checking_Account.hpp"
using namespace std;


class Debit_card
{
private:
	double cardNum;
	string expirationNum;
	int securityCode;
	string name;
	Checking_Account *chekPtr;
public:


	Debit_card(){};
	Debit_card(double c, string exp, int code, string name):cardNum(c),
						 expirationNum(exp),securityCode(code), name(name){}
	void debitPurchased(string, string, double);
	void purchasedHistory();
	void setCheckAccount(Checking_Account *p);
	string getDecription(string des){return des;}
	double getPrice(double price){return price;}
	string getDate(string date){return date;}
	
};

#endif /* Debit_card_hpp */
