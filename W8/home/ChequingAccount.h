/*Tarushpreet Singh
136579166*/
#ifndef SICT_CHEQUINGACCOUNT_H
#define SICT_CHEQUINGACCOUNT_H
#include "Account.h"

namespace sict
{
     class ChequingAccount : public Account 
	{
		double trans_fee;
		double mon_end_fee;
	 public:
		ChequingAccount(double, double, double);
		bool credit(double);
		bool debit(double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif

