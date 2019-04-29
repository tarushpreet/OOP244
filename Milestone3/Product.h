/* Tarushpreet Singh
#136579166
ts3@myseneca.ca */

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <fstream>
#include <cstring>
#include"ErrorState.h"

namespace AMA
{
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const int TAX = 13;

	class Product
	{
		char pro_type;
		char pro_sku[max_sku_length + 1];
		char pro_unit[max_unit_length + 1];
		char* pro_name_p;
		int pro_quan_on_hand;
		int pro_quan_needed;
		double pro_price;
		bool tax_status;
		void extra(const Product&);
		ErrorState error;

	protected:
		void name(const char*);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Product(const char type = 'N');
		Product(const char*, const char*, const char*, const int qnty = 0, const bool taxed = true, const double price = 0.0, const int qtyNeeded = 0);
		Product(const Product&);
		Product& operator= (const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os , bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty()const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);
	};

	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);
}
#endif

