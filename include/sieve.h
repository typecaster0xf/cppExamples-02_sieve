#pragma once

#include <vector>

using std::vector;

/*Generates prime numbers.*/
class Eratosthenes
{
public:
	
	/*maxValueInSieve: the highest number to
	consider as a possible prime number.*/
	Eratosthenes(const unsigned long maxValueInSieve);
	
	/*Runs the sieving algorithm (if it had not
	been previously run) and returns the prime
	numbers.*/
	vector<unsigned long> runSieve();
	
protected:
	
	/*A bool vector is used here rather than a
	dynamic array because it is more memory
	efficient.*/
	vector<bool> sieve;
	
	bool sieveHasNotBeenRun;
};
