#pragma once

#include <vector>

using std::vector;

class Eretosthenes
{
public:
	
	Eretosthenes(const unsigned long maxValueInSieve);
	
	vector<unsigned long> runSieve();
	
protected:
	
	/*A bool vector is used here rather than a
	dynamic array because it is more memory
	efficient.*/
	vector<bool> sieve;
	
	bool sieveHasBeenRun;
};
