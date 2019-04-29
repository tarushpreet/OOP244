/*Tarushpreet Singh
136579166*/
#include "Account.h"

namespace sict
{
	Account::Account(double _bal)
	{
		if (_bal >= 0)
		{
			current_bal = _bal;
		}
		else
		{
			current_bal = 0.0;
		}
	}

	bool Account::credit(double c_amount)
	{
		bool ss = true;
		if (c_amount >= 0)
		{
			current_bal += c_amount;
			return ss;
		}
		else
		{
			return false;
		}
	}

	bool Account::debit(double d_amount)
	{
		bool ss = true;
		if (d_amount >= 0)
		{
			current_bal -= d_amount;
			return ss;
		}
		else
		{
			return false;
		}
	}

	void Account::setbalance(double ab)
	{
		current_bal = ab;
	}

	double Account::balance() const
	{
		return current_bal;
	}

}

