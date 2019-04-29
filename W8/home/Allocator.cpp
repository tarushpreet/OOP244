/*Tarushpreet Singh
136579166*/
#include "SavingsAccount.h" 
#include "ChequingAccount.h"
using namespace std;
namespace sict 
{

	const double int_r = 0.05;
	const double transaction_fee = 0.50;
	const double monthly_fee = 2.00;

	iAccount* CreateAccount(const char* account_type, double _bal_)
	{
		iAccount* SS;
		if (account_type[0] == 'S')
		{
			SS = new SavingsAccount(_bal_, int_r);
		}
		else
		{
			if (account_type[0] == 'C')
			{
				SS = new ChequingAccount(_bal_, transaction_fee, monthly_fee);
			}
			else
			{
				SS = nullptr;
			}

		}
		return SS;
	}
}
