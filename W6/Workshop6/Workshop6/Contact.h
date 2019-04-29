#pragma once

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {

	class Contact {
		char name[20];
		long long *num;
		int no;
		long long area;
		long long phnum;
		long long c;

	public:
		Contact();
		Contact(const char* nam, long long* x, int nop);
		~Contact();
		bool isEmpty() const;
		void display();
		bool checkNum(long long n);
		Contact::Contact(const Contact & x);
		Contact & Contact::operator=(const Contact & x);
		Contact & Contact::operator+=(long long ph);
	};

}
#endif