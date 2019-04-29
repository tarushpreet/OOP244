/*Tarushpreet Singh
136579166*/
#include <iostream>
#include "SavingsAccount.h"
using namespace std;
namespace sict
{
	SavingsAccount::SavingsAccount(double _balance, double int_Rate) : Account(_balance) 
	 {
		  if (int_Rate >= 0) 
		   {
			  int_rate = int_Rate;
		   }
		  else
		   {
			  int_rate = 0;
		   }
	 }
	void SavingsAccount::monthEnd()
	{
		double _int = (balance() * int_rate);
		credit(_int);

	}
	void SavingsAccount::display(std::ostream& ostr) const
	{
		ostr.setf(ios::fixed);
		ostr.precision(2);
		cout << "Account type: Savings" << endl;
		cout << "Balance: $" << balance() << endl;
		cout << "Interest Rate (%): " << int_rate * 100 << endl;

	}

	
}
