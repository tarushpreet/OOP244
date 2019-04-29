// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include<iostream>
using namespace std;

namespace AMA {


	void Date::errCode(int errorCode)
	{
		error = errorCode;
	}


	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}


	Date::Date()
	{
		year = 0;
		day = 0;
		month = 0;
		//comp = 0;
		error = NO_ERROR;
	}

	Date::Date(int yr, int mn, int dt)
	{

		bool valid = yr<max_year && yr>min_year;
		if (valid)
		{
			valid = mn <= 12 && mn>=1;
			if (valid)
			{
				valid = dt <= mdays(mn, yr) && dt>0;
				if (valid)
				{
					day = dt;
					year = yr;
					month = mn;
					error = NO_ERROR;
					comp = year * 372 + month * 13 + day;
				}
				else
				{
					//day is incorrect
					//Date();
					year = 0;
					day = 0;
					month = 0;
					//comp = 0;
					//error = DAY_ERROR;
					comp = 0;
					errCode(DAY_ERROR);
				}
			}
			else
			{
				//month is incorrect
				//Date();
				year = 0;
				day = 0;
				month = 0;
				//comp = 0;
				//error = MON_ERROR;
				comp = 0;
				errCode(MON_ERROR);
			}
		}
		else
		{
			//year is incorrect
			//Date();
			year = 0;
			day = 0;
			month = 0;
			//comp = 0;
			//error = YEAR_ERROR;

			comp = 0;
			errCode(YEAR_ERROR);
			//error = 2;
		}
		
	}


	bool Date::operator==(const Date& rhs) const
	{
		if (this->error == 0 && rhs.error == 0)
		{
			if (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}


	bool Date::operator!=(const Date& rhs) const
	{
		
			if (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day)
			{
				return false;
			}
			else
			{
				return true;
			}
		
	}


	bool Date::operator<(const Date& rhs) const
	{
		if (this->error == 0 && rhs.error == 0)
		{
			if (this->year < rhs.year)
			{
				return true;
			}
			else if (this->year == rhs.year)
			{
				if (this->month < rhs.month)
				{
					return true;
				}
				else if (this->month == rhs.month)
				{
					if (this->day < rhs.day)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	bool Date::operator>(const Date& rhs) const
	{
		if (this->error == 0 && rhs.error == 0)
		{
			if (this->year > rhs.year)
			{
				return true;
			}
			else if (this->year == rhs.year)
			{
				if (this->month > rhs.month)
				{
					return true;
				}
				else if (this->month == rhs.month)
				{
					if (this->day > rhs.day)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}

	bool Date::operator<=(const Date& rhs) const
	{
		if (this->error == 0 && rhs.error == 0)
		{
			if (this->year < rhs.year)
			{
				return true;
			}
			else if (this->year == rhs.year)
			{
				if (this->month < rhs.month)
				{
					return true;
				}
				else if (this->month == rhs.month)
				{
					if (this->day <= rhs.day)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}
	bool Date::operator>=(const Date& rhs) const
	{
		if (this->error == 0 && rhs.error == 0)
		{
			if (this->year > rhs.year)
			{
				return true;
			}
			else if (this->year == rhs.year)
			{
				if (this->month > rhs.month)
				{
					return true;
				}
				else if (this->month == rhs.month)
				{
					if (this->day >= rhs.day)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}

		}
		else
		{
			return false;
		}
	}

	int Date::errCode() const
	{
		return error;
	}

	bool Date::bad() const
	{
		if (error != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	istream& Date::read(istream& istr)
	{
		int yr, mn, dt;
		istr >> yr;
		if (istr.fail()) {
			errCode(CIN_FAILED);
			return istr;
		}
		if (istr.get() != '/' && istr.get() != '-') {
			errCode(CIN_FAILED);
			return istr;
		}
		istr >> mn;
		if (istr.fail()) {
			errCode(CIN_FAILED);
			return istr;
		}
		if (istr.get() != '/' && istr.get() != '-') {
			errCode(CIN_FAILED);
			return istr;
		}
		istr >> dt;
		if (istr.fail()) {
			errCode(CIN_FAILED);
			return istr;
		}


		bool valid = yr<max_year && yr>min_year;
		if (valid)
		{
			valid = mn < 13 && mn > 0;
			if (valid)
			{
				valid = dt <= mdays(mn, yr) && dt>0;
				if (valid)
				{
					day = dt;
					year = yr;
					month = mn;
					error = NO_ERROR;
					comp = year * 372 + month * 13 + day;
				}
				else
				{
					//day is incorrect
					year = 0;
					day = 0;
					month = 0;
					comp = 0;
					errCode(DAY_ERROR);
				}
			}
			else
			{
				//month is incorrect
				year = 0;
				day = 0;
				month = 0;
				comp = 0;
				errCode(MON_ERROR);
			}
		}
		else
		{
			//year is incorrect
			
			year = 0;
			day = 0;
			month = 0;
			comp = 0;
			errCode(YEAR_ERROR);
		}



		if (yr < min_year || yr > max_year)
		errCode(YEAR_ERROR);
		else if (mn < 1 || mn > 12)
		errCode(MON_ERROR);
		else if (dt < 1 || dt > mdays(mn, yr))
		errCode(DAY_ERROR);
		else
		errCode(NO_ERROR);
		




		return istr;
	}


	ostream& Date::write(ostream& ostr) const
	{
		ostr << year << "/";

		if (month >= 0 && month <= 9)
			ostr << "0" << month << "/";
		else
			ostr << month << "/";
		if (day >= 0 && day <= 9)
			ostr << "0" << day;
		else
			ostr << day;

		return ostr;
	}

	ostream & operator<<(ostream & ostr, const Date & d)
	{
		d.write(ostr);
		return ostr;
	}

	istream & operator >> (istream & istr, Date & d)
	{
		d.read(istr);
		return istr;
	}

}















