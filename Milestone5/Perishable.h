//Tarushpreet Singh
//136579166
#ifndef AMA_PERISHABLE_H_
#define AMA_PERISHABLE_H_

#include "iProduct.h"
#include <iostream>
#include <fstream>

#include "Date.h"

namespace AMA {

	class Perishable : public Product {
		Date expiry_date; //holds the expiry date of the perishable objects
	public:
		Perishable();
		std::fstream &store(std::fstream &file, bool newLine= true) const;
		std::fstream &load(std::fstream &file);
		std::ostream &write(std::ostream &os, bool linear) const;
		std::istream &read(std::istream &is);
		const Date &expiry() const;
	};

}
#endif
