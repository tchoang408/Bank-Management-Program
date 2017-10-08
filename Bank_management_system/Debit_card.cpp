//
//  Debit_card.cpp
//  Bank_management_system
//
//  Created by Goat on 8/4/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//


#include "Checking_Account.hpp"
#include "Debit_card.hpp"
#include <iostream>
using namespace std;




void Debit_card::debitPurchased(string item, string date, double price  )
{
	chekPtr->addStatement(date, item, price);

}
void Debit_card::setCheckAccount(Checking_Account *acc){
	chekPtr =  acc;
}
