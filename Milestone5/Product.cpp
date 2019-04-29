
//Tarushpreet Singh
//136579166
#include "Product.h"

#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>

namespace AMA {

static constexpr char kFieldDelim = ',';


	// Creates an empty Product object with safe-state values.
	Product::Product(char TYPE) : type(TYPE), sKU{ '\0' }, Product_unit{ '\0' }, PRODUCT_NAME(nullptr), current_qty(0), needed_qty(0), PRICE(0.00), status(false), Product_error() {}
	//data members set to a safe empty state
	Product::Product(const char *SKU, const char *NAME, const char *UNIT, int ON_HAND, bool STATUS, double pRICE, int NEED) : PRODUCT_NAME(nullptr), current_qty(ON_HAND), needed_qty(NEED), PRICE(pRICE), status(STATUS), Product_error() {

		name(NAME);

		if (SKU != nullptr) {

			strncpy(sKU, SKU, sizeof(sKU));
		}

		if (Product_unit != nullptr) {

			strncpy(Product_unit, UNIT, sizeof(Product_unit));
		}
	}

	Product::Product(const Product &pr){
		PRODUCT_NAME = {'\0'};
		*this = pr; //assigning the parameter to the current object
	}


	Product::~Product() {

		name(nullptr); // calls the name function below
	}

	void Product::name(const char *p_name) {

		if (p_name == nullptr && PRODUCT_NAME != nullptr) {

			delete[] PRODUCT_NAME;
			PRODUCT_NAME = nullptr;
		}

		else if (p_name != nullptr) {

			if (PRODUCT_NAME != nullptr) {
				delete[] PRODUCT_NAME;
				PRODUCT_NAME= nullptr;
			}
			size_t size = strlen(p_name) + 1;
			PRODUCT_NAME = new char[size];
			strncpy(PRODUCT_NAME, p_name, size);
		}
	}

	const char *Product::name() const {
		if(PRODUCT_NAME[0] == '\0'){
			return nullptr;
		}
		return PRODUCT_NAME;
	}

	double Product::cost() const {
		double total = PRICE;
		if (status) {
			total *= 0.13;
		}
		return total;
	}

	void Product::message(const char *msg) {
		Product_error.message(msg);
	}


	bool Product::isClear() const {
		return Product_error.isClear();
	}
	const char *Product::sku() const {
		return sKU;
	}
	const char *Product::unit() const {
		return Product_unit;
	}
	bool Product::taxed() const {
		return status;
	}
	double Product::price() const {
		return PRICE;
	}


	Product &Product::operator=(const Product &pr) {
		type = pr.type;
		strncpy(sKU, pr.sKU, sizeof(sKU));
		strncpy(Product_unit, pr.Product_unit, sizeof(Product_unit));
		name(pr.PRODUCT_NAME);
		current_qty = pr.current_qty;
		needed_qty = pr.needed_qty;
		PRICE = pr.PRICE;
		status = pr.status;
		message(pr.Product_error.message());
		return *this;
	}

	std::istream &Product::read(std::istream &is) {
		std::cout << " Sku: ";
		std::string value_tmp;
		is >> value_tmp;
		strncpy(sKU, value_tmp.c_str(), sizeof(sKU));

		std::cout << " Name (no spaces): ";
		is >> value_tmp;
		name(value_tmp.c_str());

		std::cout << " Unit: ";
		is >> value_tmp;
		strncpy(Product_unit, value_tmp.c_str(), sizeof(Product_unit));

		std::cout << " Taxed? (y/n): ";
		is.get();  // Discards the newline character.
		char value_ch = toupper(is.get());//case sensitivity
	       if (value_ch != 'Y' && value_ch != 'N') {
			is.setstate(std::ios::failbit);
			message("Only (Y)es or (N)o are acceptable");
			return is;
		}
		status = value_ch != 'N';

		std::cout << " Price: ";
		double value_d;
		is >> value_d;
		if (is.fail()) {
			message("Invalid Price Entry");
			return is;
		}
		PRICE = value_d;

		std::cout << " Quantity on hand: ";
		int value_i;
		is >> value_i;
		if (is.fail()) {
			message("Invalid Quantity Entry");
			return is;
		}
		current_qty = value_i;

		std::cout << " Quantity needed: ";
		is >> value_i;
		if (is.fail()) { //if the data turns out to be corrupted
			message("Invalid Quantity Needed Entry");
			return is;
		}
		needed_qty = value_i;
		Product_error.clear();
		is.get();
		return is;
	}
		bool Product::operator==(const char *str) const {
		return !strcmp(sKU, str); //the strings are not equal
	}

	std::fstream &Product::store(std::fstream &file, bool insert_newline) const {
		file.put(type) << ',' << sKU << ',' << PRODUCT_NAME << ',' << Product_unit << ',' << status << ',' << PRICE << ',' << current_qty << ',' << needed_qty;
		if (insert_newline) {
			file << std::endl;
		}
		return file;
	}

	std::ostream &Product::write(std::ostream &os, bool linear) const {
		if (linear) {
			os << std::left << std::setfill(' ') << std::setw(max_sku_length);
			os << sKU << std::setw(0) << std::right << "|"; //input manipulators
			os << std::left << std::setw(20) << PRODUCT_NAME << std::setw(0) << std::right << "|";
			char cost_str[256] = { '\0' };
			sprintf(cost_str, "%.2lf", status ? PRICE * (1.0 + 0.13) : PRICE);
			os << std::setw(7) << cost_str << std::setw(0) << "|";
			os << std::setw(4) << current_qty << std::setw(0) << "|";
			os << std::left << std::setw(max_unit_length) << Product_unit << std::setw(0) << std::right << "|";
			os << std::setw(4) << needed_qty << std::setw(0) << "|";
		}
		else {
			os << " Sku: " << sKU << std::endl;
			os << " Name (no spaces): " << PRODUCT_NAME << std::endl;
			std::streamsize old_precision = os.precision();
			os << " Price: " << std::fixed << std::setprecision(2) << PRICE << std::setprecision(old_precision) << std::endl;
			os.unsetf(std::ios::floatfield);
			os << " Price after tax: ";
			if (status) {
				os << std::fixed << std::setprecision(2) << total_cost() << std::setprecision(old_precision) << std::endl;
				os.unsetf(std::ios::floatfield);
			}
			else {
				os << " N/A" << std::endl;
			}
			os << " Quantity on Hand: " << current_qty << " " << Product_unit<< std::endl;
			os << " Quantity needed: " << needed_qty;
		}
		return os;
	}

	std::fstream &Product::load(std::fstream &file) {
		Product tmp;
		size_t field_count = 1;
		bool done = false;
		while (!file.eof() && !done) {
			std::string field_tmp;
			std::getline(file, field_tmp, ',');

			switch (field_count++) {
			case 1:
				strncpy(tmp.sKU, field_tmp.c_str(), sizeof(tmp.sKU));
				break;
			case 2:
				tmp.name(field_tmp.c_str());
				break;
			case 3:
				strncpy(tmp.Product_unit, field_tmp.c_str(), sizeof(tmp.Product_unit));
				break;
			case 4:
				tmp.status = strtol(field_tmp.c_str(), NULL, 10);
				break;
			case 5:
				tmp.PRICE = strtod(field_tmp.c_str(), NULL);
				break;
			case 6:
				tmp.current_qty = strtol(field_tmp.c_str(), NULL, 10);
				break;
			case 7:
				tmp.needed_qty = strtol(field_tmp.c_str(), NULL, 10);
				done = true;
				break;
			}
		}
		*this = tmp;
		return file;
	}

	double Product::total_cost() const {
		double total = PRICE * current_qty;
		if (status) {
			total *= 1.00 + 0.13;
		}
		return total;
	}

	void Product::quantity(int Received) {
		current_qty = Received;
	}
	bool Product::isEmpty() const {


	bool flag = false;
		if (PRODUCT_NAME[0] == '\0') {
			flag = true;
		}
		else {
			flag = false;
		}
		return flag;

	}

	int Product::qtyNeeded() const {
		return needed_qty;
	}
	int Product::quantity() const {
		return current_qty;
	}


	bool Product::operator>(const char *SKU) const {
		return strcmp(sKU, SKU) > 0;
	}

	bool Product::operator>(const iProduct &pr) const {
	       // return *this > pr.sku();
		int check= strcmp(sKU, pr.name());
		if(check >0){ return true;}
		else{ return false;}
	}

	int Product::operator+=(int ADD) {
		if (ADD > 0) {
			current_qty+=ADD;;
		}
		return current_qty;
	}

	ErrorState &Product::error() {
		return Product_error;
	}

	std::ostream &operator<<(std::ostream &os, iProduct &product) {
		return product.error().message() == nullptr || strlen(product.error().message()) == 0U ? product.write(os, true) : os << product.error().message();
	}        // return product.write(os, true);

	std::istream &operator>>(std::istream &is, iProduct &product) {
		return product.read(is); // calling the read function on the iProduct obj
	}

	double operator+=(double &cst, const iProduct &product) {
		return cst += product.total_cost();
	}

}
