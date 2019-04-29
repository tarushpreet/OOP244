/*Tarushpreet Singh
136579166*/

#include<iostream>
#include<cstring>
#include"Data.h"
using namespace std;
namespace sict {
	void answers(const int* year, const int* population, const int* violentCrime, double* violentCrimeRate, const int* grandTheftAuto, const int n) {
		int Population_change,Higest_pop,lowest_pop;
		Higest_pop = population[n - 1];
		lowest_pop = population[0];
		Population_change = (Higest_pop - lowest_pop);
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout << std::fixed;
		cout.precision(2);
		cout << static_cast<double>(Population_change) / (1000000.0) << " million" << endl;

		cout << "Violent Crime ";
		if (violentCrime[0] > violentCrime[n - 1]) {

			 cout <<"trend is down" << endl;;
		}
		else {
			cout << "trend is up";
		}


		double occurance = average(grandTheftAuto, n);
		std::cout << "There are ";
		cout << std::fixed;
		cout.precision(2);
		cout << static_cast<double>(occurance / 1.0E6) << " million Grand Theft Auto incidents on average a year" << endl;

		int Minimum_crime_ = min(violentCrimeRate, 5);
		cout << "The Minimum Violent Crime rate was " << Minimum_crime_ << endl;
		
		int Maximum_crime_ = max(violentCrimeRate, 5);
		cout << "The Maximum Violent Crime rate was " << Maximum_crime_ << endl;
	}
}