//
//  Saving_Account.cpp
//  Bank_management_system
//
//  Created by Goat on 8/21/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#include "Saving_Account.hpp"
#include <iomanip>

Saving_Account::Saving_Account(double acc, double rout, double bal)
{
	accountNum = acc;
	routingNum = rout;
	balance = bal;
}
void Saving_Account::checkBalance()
{
	
	cout << setprecision(8) <<"Account number: " << accountNum << endl;
	cout << setprecision(8) <<"Routing number: " << routingNum << endl;
	cout << "Balance: $" << balance <<endl;
}
