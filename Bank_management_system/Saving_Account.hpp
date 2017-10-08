//
//  Saving_Account.hpp
//  Bank_management_system
//
//  Created by Goat on 8/21/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//

#ifndef Saving_Account_hpp
#define Saving_Account_hpp

#include <stdio.h>
#include <iostream>

using namespace std;


class Saving_Account
{
private:
	double accountNum;
	double balance;
	double routingNum;
	double interestRate;
public:
	Saving_Account(double, double , double);
	double getBalance(){return balance;}
	void checkBalance();
	
	
	
	
	
};
#endif /* Saving_Account_hpp */
