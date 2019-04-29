// TODO: insert header files
#include<iostream>
#include<cstring>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
namespace sict {
	
	class Fraction {
		// TODO: declare instance variables 
		int num;
		int den;
		// TODO: declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int n, int d);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
	};
	
	
	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		num = 1;
		den = 1;
	}
	// TODO: implement the two-argument constructor
	Fraction::Fraction(int n, int d)
	{
		if (n > 0 && d > 0)
		{
			num = n;
			den = d;
		}
		else
			num = 1;
			den = 1;
	}
	// TODO: implement the max query
	int Fraction::max() const
	{
		if (num > den)
		{
			return num;
		}
		else
			return den;
	}
	// TODO: implement the min query
	int Fraction::min() const
	{
		if (num > den)
		{
			return den;
		}
		else
			return num;
	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int div = gcd();
		num = num / div;
		den = den / div;
	}
	// TODO: implement the display query
	void Fraction::display() const
	{
		if (!isEmpty && den != 1)
		{
			cout << num << "/" << den << "\n";
		}
		else if (!isEmpty && den == 1)
		{
			cout << num << "\n";
		}
		else
			cout << "no fraction stored\n";
	}
	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		if (num == 1 && den == 1)
		{
			return true;
		}
		else
			return false;
	}
	// TODO: implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const
	{
		if (!isEmpty() && !rhs.isEmpty)
		{
			int a = ((this->num * rhs.den) + (rhs.num * this->den)) / this->den*rhs.den;
			.reduce();
		}
		else

		
	}




}