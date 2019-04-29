#include<iostream>
#include"Contact.h"
#include<cstring>

using namespace std;
namespace sict {

	Contact::Contact()
	{
		name[0] = '\0';
		num = nullptr;
		no = 0;
	}

	Contact::Contact(const char* nam, long long* x, int nop)
	{
		int f = 0;
		int rs = 0;
		bool valid = nam != nullptr && strcmp(nam, "") != 0;
		if (valid)
		{
			strncpy(name, nam, 20);
			name[19] = '\0';
			valid = x != nullptr && nop > 0;

			if (valid)
			{
				for (int i = 0; i < nop; i++)
				{
					if (checkNum(x[i]))
					{
						f++;
					}
				}
			}
			num = new long long[f];
			for (int i = 0; i < nop; i++)
			{
				if (checkNum(x[i]))
				{
					//accept
					num[rs] = x[i];
					rs++;
					//cout << num[rs];
				}
			}
			no = rs;
		}
		else
		{
			name[0] = '\0';
			num = nullptr;
			no = 0;
		}

	}

	bool Contact::checkNum(long long n)
	{
		bool val = n >= 10000000000 && n <= 999999999999;
		if (val)
		{
			int phnum = n % 10000000;
			int area = ((n - phnum) / 10000000) % 1000;
			int c = ((((n - phnum) / 10000000) - area) / 1000);
			val = phnum >= 1000000 && phnum <= 9999999 && area >= 100 && area <= 999 && c <= 99 && c >= 1;
			if (val)
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

	Contact::~Contact()
	{
		delete[] num;
	}

	bool Contact::isEmpty() const
	{
		if (name == nullptr || name[0] == '\0')
		{
			return 1;
		}
		else return 0;
	}

	void Contact::display()
	{
		if (isEmpty())
		{
			cout << "Empty contact!\n";
		}
		else
		{
			cout << name << "\n";
			for (int i = 0; i < this->no; i++)
			{
				int phnum = this->num[i] % 10000000;
				int last = phnum % 10000;
				phnum = (phnum - last) / 10000;
				int area = ((this->num[i] - phnum) / 10000000) % 1000;
				int c = ((((this->num[i] - phnum) / 10000000) - area) / 1000);
				cout << "(+" << c << ") " << area << " " << phnum << "-";
				cout.width(4);
				cout.fill('0');
				cout<< last << "\n";
			}

		}
	}
	
	Contact::Contact(const Contact & x)
	{
		strncpy(name, x.name, 20);
		name[19] = '\0';
		no = x.no;

		if (x.num != nullptr)
		{
			num = new long long[no];
			for (int s = 0; s < no; s++)
			{
				num[s] = x.num[s];
			}
		}
		else
		{
			num = nullptr;
		}
	}
	

	Contact & Contact::operator=(const Contact & x)
	{
		if (this != &x)
		{
			strncpy(name, x.name, 20);
			name[19] = '\0';
			no = x.no;
			delete[]num;

			if (x.num != nullptr)
			{
				num = new long long[no];

				for (int g = 0; g < no; g++)
					num[g] = x.num[g];
			}
			else
			{
				num = nullptr;
			}
		}

		return *this;
	}

	Contact & Contact::operator+=(long long ph)
	{
		bool valid = checkNum(ph);
		if (valid)
		{
			long long *a = nullptr;
			a = new long long[no + 1];
			for (int s = 0; s < no; s++)
			{
				a[s] = num[s];
			}
			a[no] = ph;
			no++;
			delete[]num;
			num = a;
		}
		return *this;
	}







}