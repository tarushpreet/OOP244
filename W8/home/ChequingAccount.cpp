/*Tarushpreet Singh
136579166*/

#include <iostream>
#include <iomanip>
#include "ChequingAccount.h"
using namespace std;
namespace sict
{
	ChequingAccount::ChequingAccount(double initial_bal, double tra_fees, double m_end_fees) : Account(initial_bal)
	{
		if (tra_fees > 0.0)
		{
			trans_fee = tra_fees;
		}
		else
		{
			trans_fee = 0.0;
		}
		if (m_end_fees > 0.0)
		{
			mon_end_fee = m_end_fees;
		}
		else
		{
			mon_end_fee = 0.0;
		}
	
	}

	bool ChequingAccount::credit(double am)
	{
		bool ss = true;
		if (Account::credit(am))
		{
			double new_balance = (balance() - trans_fee);
			setbalance(new_balance);
			return ss;
		}
		else
		{
			return false;
		}
	}
	bool ChequingAccount::debit(double am)
	{
		bool ss = true;
		if (Account::debit(am))
		{
			double new_balance = (balance() - trans_fee);
			setbalance(new_balance);
			return ss;
		}
		else
		{
			return false;
		}
	}
	void ChequingAccount::monthEnd()
	{
			double new_balance = (balance() - mon_end_fee - trans_fee);
			setbalance(new_balance);
	}
	void ChequingAccount::display(std::ostream& ostr) const
	{
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Account type: Chequing" << endl;
		ostr << "Balance: $" << balance() << endl;
		ostr << "Per Transaction Fee: " << fixed << setprecision(2) << trans_fee << endl;
		ostr << "Monthly Fee: " << fixed << setprecision(2) << mon_end_fee << endl;
	}
}
