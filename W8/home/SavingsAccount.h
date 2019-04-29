/*Tarushpreet Singh
136579166*/

#ifndef SICT_SAVINGSACCOUNT_H
#define SICT_SAVINGSACCOUNT_H
#include "Account.h"
namespace sict 
 {
    class SavingsAccount : public Account 
	 {
		  double int_rate;

	public:

		  SavingsAccount(double, double);
		  void monthEnd();
		  void display(std::ostream&) const;
	};
}
#endif

