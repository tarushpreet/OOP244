#include "Data.h"

namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	//



	/*bool readRow(std::istream& input, const char* name, double* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	bool readRow(std::istream& input, const char* name, int* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	*/
	// answers outputs statistics for visual validation of data
	//
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"

		double popChange = 0;
		popChange = population[n - 1] - population[0];

		cout
			<< "Population change from " << year[0]
			<< " to " << year[n - 1] << " is "
			<< popChange / 1000000;

		if (popChange >= 100000 && popChange <= 999999)
		{
			cout << " Thousand" << endl;
		}
		else if(popChange >= 1000000 && popChange <= 9999999)
		{
			cout << " million" << endl;
		}
		else
		{
			cout << endl;
		}


		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005

		cout << "Violent Crime trend is ";

		if (violentCrime[0] < violentCrime[n - 1])
		{
			cout << "down" << endl;
		}
		else
		{
			cout << "up" << endl;
		}




		// Q3 print the GTA number accurate to 0 decimal places

		cout << "There are ";
		int gtas = 0;

		for (int i = 0; i < n; i++)
		{
			gtas += grandTheftAuto[i];
		}

		cout << average(grandTheftAuto, n) / 100000 << " million Grand Theft Auto incidents on average a year";


		// Q4. Print the min and max violentCrime rates

		cout << "The Minimum Violent Crime rate was " << min(violentCrimeRate, n) << endl
			<< "The Maximum Violent Crime rate was " << max(violentCrimeRate, n);


	}
}