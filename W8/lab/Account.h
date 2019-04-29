/*Tarushpreet Singh
136579166*/
#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H
#include "iAccount.h"
namespace sict
{
	class Account : public iAccount
	{
		double current_bal;

	protected:
		double balance() const;

	public:
		Account(double bal);
		bool credit(double);
		bool debit(double);
	    

	};
	iAccount* CreateAccount(const char* account_type, double _bal_);

}

#endif
