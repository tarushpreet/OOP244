//Tarushpreet Singh
//136579166
#include "Product.h"
#include "Perishable.h"
#include"Date.h"
#include"iProduct.h"

#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
#include<iostream>
#include<cstdio>

namespace AMA {

	Perishable::Perishable() : Product('P') {} //calls its base class constructor and passes a character to it

	std::fstream &Perishable::store(std::fstream &file, bool newLine) const {
		Product::store(file, false) << ',' << expiry_date; //calls its base class store function, inserts a comma after each record and appends the expiry date at the end
		if (newLine) {
			file << "\n";
		}
		return file;
	}
	std::fstream &Perishable::load(std::fstream &file) {
		Product::load(file); //calls its base class function
		file >> expiry_date;
		return file;
	}
	std::ostream &Perishable::write(std::ostream &os, bool linear) const {
		Product::write(os, linear); //calls its base class function
		if (isEmpty()) { //a product member function
			return os;
		}
		if (linear) { //if true
			os << expiry_date;
		}
		else {
			os << std::endl << " Expiry date: " << expiry_date;
		}
		return os;
	}
	std::istream &Perishable::read(std::istream &is) {
		Product::read(is); //same phenomenon as above
		if (is.fail()) {
			return is; //fail is a default istream member function that checks if the procedure will fail or not
		}
		std::cout << " Expiry date (YYYY/MM/DD): ";
		is >> expiry_date;
		if (expiry_date.bad()) { //default istream function that checks if the data is corrupted or not
			switch (expiry_date.errCode()) {
			case CIN_FAILED:  //this can also be done using if else
				message("Invalid Date Entry");
				break;
			case YEAR_ERROR:
				message("Invalid Year in Date Entry");
				break;
			case MON_ERROR:
				message("Invalid Month in Date Entry");
				break;
			case DAY_ERROR:
				message("Invalid Day in Date Entry");
				break;
			}
		}
		else {
			error().clear(); //set the data to a good state
		}
		return is;
	}
	const Date &Perishable::expiry() const {
		return expiry_date;
	}

}
