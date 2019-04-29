/*Tarushpreet Singh
136579166*/
#include "SavingsAccount.h" 
using namespace std;
namespace sict {

	const double int_r = 0.05;
	iAccount* CreateAccount(const char* account_type, double _bal_)
	{
		iAccount* SS = nullptr;
		if (account_type[0] == 'S')
		{
			SS = new SavingsAccount(_bal_, int_r);
			
		}
		return SS;
	}

}
