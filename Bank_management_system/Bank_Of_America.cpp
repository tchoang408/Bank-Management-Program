//
//  Bank_Of_America.cpp
//  Bank_management_system
//
//  Created by Goat on 8/2/17.
//  Copyright © 2017 Tam Hoang. All rights reserved.
//




#include "Bank_Of_America.hpp"
#include "Checking_Account.hpp"
#include "Saving_Account.hpp"
#include <iomanip>
#include <fstream>
#include <regex>
#include <list>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


Bank_Of_America::Bank_Of_America()
{
	unsigned seed = time(0);
	srand(seed);
	initializedBranch();
	createSampleAccount();
	cout << setw(70) << "Welcome to Bank of America Employee Banking System\n\n";
	bool valid = true;
	while(valid){
		cout << "Enter BOF branch number: ";
		cin >> branchNumber;
		cout << "Enter employee ID number: ";
		cin >> employeeIDNumber;
		bool branch = false;
		bool employee = false;
		
		for(int row = 0; row < branchInfor.size(); row++)
		{
			if(branchInfor[row][0] == branchNumber)
			{
				branch = true;
				for(int col = 0; col < branchInfor[row].size(); col++)
				{
					if(branchInfor[row][col] == employeeIDNumber)
					{
						employee = true;
						
					}
				}
			}
		}

		if(branch == true && employee == true)
			valid = false;
		else if(branch == false || employee == false){
			cout << "The information enter was incorrect. Please enter again.\n";
			valid = true;
		}
	}
	
	employeeMenu();
}
Bank_Of_America::~Bank_Of_America()
{}
void Bank_Of_America::createSampleAccount()
{
	PersonalAccount *newAccount = new PersonalAccount("Tam C Hoang", 12367876);
	newAccount->createNewChecking(12345678, 87654321, 5000);
	newAccount->createNewSaving(35742356, 38976542, 3400);
	privateAccount.push_back(*newAccount);
}
void Bank_Of_America::checkCustomerAccount()
{
	double account;
	bool found = false;
	do{
		cout << "Enter the customer account number: ";
		cin >> account;
		PersonalAccount *ptr = NULL;
		for( auto i: privateAccount){
			if(i.getChecking()->getAccountNum() == account){
				ptr = &i;
				found = true;
				break;
			}
		}
		if(found)
			menu(*ptr);
		else
			cout << "Account number is incorrect. Please try again." << endl;
		
	}while(!found);

}
void Bank_Of_America::employeeMenu()
{
		char choice;
		cout <<  "----------------------------------------------------" << endl;
		cout << right <<setw(30) <<"Menu" << setw(25) << "|\n\n";
		cout << left <<"1." << setw(25) << "\tCheck Customer Account" << right << setw(25) << "|\n";
		cout << left <<"2." << setw(25) << "\tCreate New Account" << right << setw(25) << "|\n";
		cout << left <<"3." << setw(25) << "\tQuit Program" << right << setw(25) << "|\n";
		cout <<  "----------------------------------------------------" << endl;
		cout << "Enter your an option: ";
		cin >> choice;
		
		switch(choice)
		{
			case '1': checkCustomerAccount();
				employeeMenu();
				break;
			case '2': createNewPersonalAccount();
				employeeMenu();
				break;
			case '3':
				break;
			default: cout << "Incorrect choice.\n";
		}

}
void Bank_Of_America::initializedBranch()
{
	fstream file;
	file.open("BankOfAmericaBranchCode.txt");
	if(file.is_open())
		cout << "File have been successfully open.\n";
	else
		cout << "File was unsuccessfully open.\n";
	
	regex location("<location>");
	regex branch("\\d{4}");
	regex id("\\d{5}");
	string line;
	smatch m;
	vector<string> employID;
	getline(file, line);
	while(!file.eof()){
		if(regex_search(line,location)){
			regex_search(line,m,branch);
			employID.push_back(m[0].str());
			//cout << "branch Code: " << m[0].str() << endl;
		}
		do{
			getline(file, line);
			if(regex_search(line,m,id)){
				employID.push_back(m[0].str());
				//cout << m[0].str() << endl;
			}
			if(file.eof())
				break;

		}while(regex_search(line,m,id));
			branchInfor.push_back(employID);
			employID.clear();
	}
}
void Bank_Of_America:: createNewPersonalAccount()
{
	string name;
	double ssn;
	double balance, balance1;
	cout << "Enter account owner name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter account owner Social security number:";
	cin >> ssn;
	cout << "What is the initial Balance in checking account: ";
	cin >> balance;
	cout << "What is the initial Balance in saving account: ";
	cin >> balance1;
	double account =  (rand() % (99999999 - 10000000 + 1)) + 10000000;
	double routing =  (rand() % (99999999 - 10000000 + 1)) + 10000000;
	double account1 =  (rand() % (99999999 - 10000000 + 1)) + 10000000;
	double routing1 =  (rand() % (99999999 - 10000000 + 1)) + 10000000;
	PersonalAccount *newAccount = new PersonalAccount(name, ssn);
	
	newAccount->createNewChecking(account, routing, balance);
	newAccount->createNewSaving(account1, routing1, balance1);
	privateAccount.push_back(*newAccount);
		cout << "New Checking and Saving Account had been created.\n";
	cout << "Account Name: " << name << endl;
	cout << "Cheking account number: " << setprecision(8) << account << endl;
	cout << "Saving account number: " << setprecision(8) << account1 << endl;
	cout << "Checking account balance: $" << balance << endl;
	cout << "Saving account balance: $" << balance1 << endl;
}
void Bank_Of_America::menu(PersonalAccount account)
{
	char choice;
	double amount;
	char cont = 'n';
	do{
		cout <<  "-----------------------------------------------" << endl;
		cout << right <<setw(30) <<"Menu" << setw(20) << "|\n\n";
		cout << left <<"1." << setw(20) << "\tChecking Account" << right << setw(25) << "|\n";
		cout << left <<"2." << setw(20) << "\tSaving Account" << right << setw(25) << "|\n";
		cout << left <<"3." << setw(20) << "\tDeposit" << right << setw(25) << "|\n";
		cout << left <<"4." << setw(20) << "\tWithdraw" << right << setw(25) << "|\n";
		cout << left <<"5." << setw(20) << "\tBack " << right << setw(25) << "|\n";
		cout <<  "-----------------------------------------------" << endl;
		cout << "Enter your an option: ";
		cin >> choice;
		
		switch(choice)
		{
			case '1': account.getChecking()->checkBalance();
				break;
			case '2': account. getSaving()->checkBalance();
				break;
			case '3':
				cout << "How much would you like to deposit? ";
				cin >> amount;
				account.getChecking()->deposit(amount);
				break;
			case '4':
				cout << "How much would you like to withraw? ";
				cin >> amount;
				account.getChecking()->withdraw(amount);
				break;
			case '5': employeeMenu();
			default: cout << "Incorrect choice\n";
				
		}
		cout << "Do you want to continue?(y/n)";
		cin >> cont;
	}while(cont == 'y');
	
}

