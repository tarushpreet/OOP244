/* Tarushpreet Singh
#136579166
ts3@myseneca.ca */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
//#include<fstream>
//#include"Product.h"
#include "MyProduct.h"
#include"ErrorState.h"
using namespace std;

namespace AMA
{
	void Product::name(const char* pr_name)
	{
		if (pr_name != nullptr)
		{
			if (pro_name_p != nullptr)
			{
				delete[] pro_name_p;
				pro_name_p = nullptr;
			}

			pro_name_p = new char[(strlen(pr_name)) + 1];
			strcpy(pro_name_p, pr_name);

		}
		else
			pro_name_p = nullptr;
	}

	const char* Product::name() const
	{
		if (pro_name_p != nullptr)
			return pro_name_p;
		else
			return nullptr;
	}

	const char* Product::sku() const
	{
		return pro_sku;
	}


	const char* Product::unit() const
	{
		return pro_unit;
	}


	bool Product::taxed() const
	{
		return tax_status;
	}


	double Product::price() const
	{
		return pro_price;
	}

	double Product::cost() const
	{
		double total_value = 0;
		if (tax_status)
		{
			total_value = pro_price * (((double)TAX / 100) + 1);
		}
		else
		{
			total_value = pro_price;
		}

		return total_value;
	}


	void Product::message(const char* error_message)
	{
		error.message(error_message);
	}


	bool Product::isClear() const
	{
		return !error.isClear();
	}

	void Product::extra(const Product& product)
	{
		pro_type = product.pro_type;
		strncpy(pro_sku, product.pro_sku, strlen(product.pro_sku));
		pro_sku[strlen(product.pro_sku)] = '\0';
		strncpy(pro_unit, product.pro_unit, strlen(product.pro_unit));
		pro_unit[strlen(product.pro_unit)] = '\0';
		pro_quan_on_hand = product.pro_quan_on_hand;
		pro_quan_needed = product.pro_quan_needed;
		pro_price = product.pro_price;
		tax_status = product.tax_status;
		pro_name_p = nullptr;
		name(product.pro_name_p);
	}


	Product::Product(const char type)
	{
		pro_type = type;
		pro_sku[0] = '\0';
		pro_unit[0] = '\0';
		pro_name_p = nullptr;
		pro_quan_on_hand = 0;
		pro_quan_needed = 0;
		pro_price = 0;
		tax_status = false;
	}

	Product::Product(const char *p_sku,const char *p_name,const char *p_unit,const int p_quantity,const bool taxed,double p_price, const int quan_needed)
	 {
		if (p_sku != nullptr)
		 {
			strncpy(pro_sku, p_sku, strlen(p_sku));
			pro_sku[strlen(p_sku)] = '\0';
		 }

		pro_name_p = nullptr;
		name(p_name);
		strncpy(pro_unit, p_unit, strlen(p_unit));
		pro_unit[strlen(p_unit)] = '\0';
		pro_quan_on_hand = p_quantity;
		tax_status = taxed;
		pro_price = p_price;
		pro_quan_needed = quan_needed;

	}

	Product::Product(const Product& temp)
	{
		pro_type = temp.pro_type;
		strncpy(pro_sku, temp.pro_sku, strlen(temp.pro_sku));
		pro_sku[strlen(temp.pro_sku)] = '\0';
		strncpy(pro_unit, temp.pro_unit, strlen(temp.pro_unit));
		pro_unit[strlen(temp.pro_unit)] = '\0';
		pro_quan_on_hand = temp.pro_quan_on_hand;
		pro_quan_needed = temp.pro_quan_needed;
		pro_price = temp.pro_price;
		tax_status = temp.tax_status;
		pro_name_p = nullptr;
		name(temp.pro_name_p);
	}


	Product& Product::operator=(const Product& temp)
	{
		if (this != &temp)
		{
			delete[] pro_name_p;
			pro_name_p = nullptr;
			pro_type = temp.pro_type;
			strncpy(pro_sku, temp.pro_sku, strlen(temp.pro_sku));
			pro_sku[strlen(temp.pro_sku)] = '\0';
			strncpy(pro_unit, temp.pro_unit, strlen(temp.pro_unit));
			pro_unit[strlen(temp.pro_unit)] = '\0';
			pro_quan_on_hand = temp.pro_quan_on_hand;
			pro_quan_needed = temp.pro_quan_needed;
			pro_price = temp.pro_price;
			tax_status = temp.tax_status;
			pro_name_p = nullptr;
			name(temp.pro_name_p);
		}
		return *this;
	}


	Product::~Product()
	{
		delete[] pro_name_p;
		pro_name_p = nullptr;
	}


	std::fstream& Product::store(std::fstream& file, bool newLine) const
	{
		file << pro_type << ", " << pro_sku << ", " << pro_unit << ", ";
		file << pro_name_p << ", " << pro_quan_on_hand << ", " << pro_quan_needed << ", ";
		file << pro_price << ", " << tax_status << ", ";

		if (newLine)
			file << endl;

		return file;
	}


	std::fstream& Product::load(std::fstream& file)
	{
		Product temp;
		file >> temp.pro_type
			>> temp.pro_sku
			>> temp.pro_unit;
		file >> temp.pro_name_p
			>> temp.pro_quan_on_hand
			>> temp.pro_quan_needed;
		file >> temp.pro_price
			>> temp.tax_status;
		*this = temp;

		return file;
	}


	std::ostream& Product::write(std::ostream& os, bool linear) const
	{
		if (linear)
		{
			os.setf(ios::left);
			os.width(max_sku_length);
			os << pro_sku << "|";

			os.width(20);
			os << pro_name_p << "|";
			os.unsetf(ios::left);

			os.setf(ios::fixed);
			os.width(7);
			os.precision(2);
			os << cost() << "|";

			os.width(4);
			os << pro_quan_on_hand << "|";

			os.setf(ios::left);
			os.width(10);
			os << unit() << "|";

			os.unsetf(ios::left);
			os.width(4);
			os << pro_quan_needed << "|";
			os.setf(ios::fixed);
		}
		else
		{
			os << "Sku: " << sku() << endl;
			os << "Name: " << name() << endl;
			os << "Price: " << price() << endl;
			if (taxed())
				os << "Price after tax: " << cost() << endl;
			else
				os << "N/A" << endl;

			os << "Quantity on hand: " << pro_quan_on_hand << endl;
			os << "Quantity needed: " << pro_quan_needed << endl;
		}
		return os;
	}


	std::istream& Product::read(std::istream& is)
	{

		char sku_s[max_sku_length + 1];
		char name_s[max_name_length + 1];
		char unit_s[max_unit_length + 1];
		int  units_quantity, pro_need;
		double price_s;
		char tax_s;
		bool real_tax = false;
		bool ss = false;

		while (ss == false)
		{
			ss = true;
			cout << " Sku: "; is.getline(sku_s, max_sku_length);
			cout << " Name (no spaces): "; is.getline(name_s, max_name_length);
			cout << " Unit: "; is.getline(unit_s, max_unit_length);
			cout << " Taxed? (y/n): "; is >> tax_s;

			if ((tax_s == 'Y' || tax_s == 'y') || tax_s == 'n' || tax_s== 'N')
			{
				if (tax_s == 'Y' || tax_s == 'y')
					real_tax = true;
				else if (tax_s == 'n' || tax_s == 'N')
					real_tax = false;
			}
			else
			{
				error.message("Only (Y)es or (N)o are acceptable");
				is.setstate(ios::failbit);
				break;
			}

			cout << " Price: ";
			is >> price_s;
			if (is.fail())
			{
				error.message("Invalid Price Entry");
				break;
			}
			cout << " Quantity on hand: ";
			is >> units_quantity;
			if (is.fail())
			{
				error.message("Invalid Quantity Entry");
				break;
			}

			cout << " Quantity needed: ";
			is >> pro_need;
			if (is.fail())
			{
				error.message("Invalid Quantity Needed Entry");
				break;
			}

			is.clear();
			is.ignore();
		}

		if (!is.fail())
		{
			strcpy(pro_sku, sku_s);
			this->name(name_s);
			strcpy(pro_unit, unit_s);
			pro_quan_on_hand = units_quantity;
			tax_status = real_tax;
			pro_price = price_s;
			pro_quan_needed = pro_need;
		}
		return is;
	}

	bool Product::operator==(const char *s_sku) const 
	{
		bool flag;
		if (sku() == s_sku)
			flag = true;
		else
			flag = false;
		return flag;
	}

	double Product::total_cost() const
	{
		double total_price;
		total_price = cost()*pro_quan_on_hand;
		return total_price;
	}

	void Product::quantity(int quan_on_hand)
	{
		pro_quan_on_hand = quan_on_hand;
	}

	bool Product::isEmpty() const
	  {
		bool flag;
		if (pro_sku[0] == '\0' && pro_name_p == nullptr && pro_price == 0 &&
			pro_quan_needed == 0 && pro_quan_on_hand == 0 && tax_status == false)
		{
			flag = true;
		}
		else 
		{
			flag = false;
		}
		return flag;
	  }


	int Product::qtyNeeded() const
	{
		return pro_quan_needed;
	}


	int Product::quantity() const
	{
		return pro_quan_on_hand;
	}

	bool Product::operator>(const char *temp_sku) const 
	{
		bool _bool;
		if (!(sku() > temp_sku))
			_bool = false;
		else
			_bool = true;
		return _bool;
	}

	bool Product::operator>(const Product &pr) const
	{
		bool _bool;
		if (!(strlen(pro_name_p) > strlen(pr.pro_name_p)))
			_bool = false;
		else
			_bool = true;
		return _bool;
	}

	int Product::operator+=(int un)
	{
		int temp;
		if (un < 0)
			temp = pro_quan_on_hand ;
		else
			temp = pro_quan_on_hand += un;
		return temp;
	}

	ostream& operator<<(std::ostream& os, const Product& product)
	{
		product.write(os, true);
		return os;
	}
	istream& operator>>(istream& is, Product& product)
	{
		product.read(is);
		return is;
	}

	double operator+=(double &cost, const Product &ref) {
		cost += ref.total_cost();
		return cost;
	}
}
