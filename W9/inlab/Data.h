/*Tarushpreet Singh
136579166*/

#ifndef SICT_DATA_H
#define SICT_DATA_H
#include<cstring>
#include<iostream>


using namespace std;
namespace sict {
	
	const int LARGEST_NUMBER = 1000000000; 
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	template <typename Maximum>
	Maximum max(const Maximum* data, int n)
	{
		int Highest_number = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (Highest_number <= data[i]) {
				Highest_number = data[i];
			}
		}
		return Highest_number;
	}
	template <typename Minimum>
	Minimum min(const Minimum* data, int n)
	{
		int lowest_number = LARGEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (lowest_number > data[i]) {
				lowest_number = data[i];
			}
		}
		return lowest_number;
	}

	
	template <typename Total_number>
	Total_number sum(Total_number *data[], int n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}
		return sum;
	}

	template <typename Tavg>
	double average(Tavg data[], int n)
	{
		int sum = 0;
		int avg = 0;
		for (int i = 0; i < n; i++) {
			sum += data[i];
		}
		avg = sum / n;
		return avg;
	}

	template<class Tread>
	bool read(std::istream& input, Tread* data, int n)
	{
		char comma;

		
		for (int i = 0; i< n; i++)
		{
			Tread number;

			input >> comma;
			if (comma != ',') return false;
			if (input >> number)
			{
				data[i] = number;
			}
			else
			{
				return false;
			}

		}
		return true;
	}

	template<class Display>
	void display(const char* line, Display *data, int n)
	{
		std::cout.width(20);
		std::cout << line;
		for (int i = 0; i < n; i++)
		{
			std::cout.width(COLUMN_WIDTH);
			std::cout << data[i];
		}
		std::cout << std::endl;
	}


	void answers(const int* year, const int* population, const int* violentCrime, double* violentCrimeRate, const int* grandTheftAuto, const int n);
	
	template<typename readR>
	readR readRow(std::istream& input, const char* name, readR* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();
		if (ok) {

			input.get(rowname, 2000, ',');
			if (strcmp(rowname, name) != 0) {

				std::cout << "Cannot parse line for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)

			ok = read(input, data, n);


		input.ignore(2000, '\n');
		return ok;

	}

}
#endif // !SICT_DATA_H
