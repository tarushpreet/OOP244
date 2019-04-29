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
		int f;
		bool valid = nam != nullptr && strcmp(nam, "") != 0;
		if (valid)
		{
			strncpy(name, nam, 19);
			name[20] = '\0';
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
			for (int i = 0; i<f; i++)
				if (checkNum(x[i]))
				{
					//accept
					no = nop;
					num[i] = x[i];
				}
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
		bool val = n > 9999999999 && n < 1000000000000;
		int phnum = n % 10000000;
		int area = ((n - phnum) / 10000000) % 1000;
		int c = ((((n - phnum) / 10000000) - area) / 1000);
		val = phnum / 1000000 > 0 && area / 100 > 0 && c > 0;
		if (val)
		{
			return true;
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
		if (name==nullptr || name[0]=='\0')
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
			cout << name<<"\n";
			for (int i = 0; i < this->no; i++)
			{
				int phnum = this->no % 10000000;
				int area = ((this->no - phnum) / 10000000) % 1000;
				int c = ((((this->no - phnum) / 10000000) - area) / 1000);
				//breakNum(this->num[i]);

				cout << "(+" << c << ") " << area << " " << phnum << "\n";
			}
			
		}
	}

}
