#include "sieve.h"

Eretosthenes::Eretosthenes(const unsigned long maxValueInSieve):
sieve(maxValueInSieve >> 1, true),
sieveHasBeenRun(false)
{}

vector<unsigned long> 
Eretosthenes::runSieve()
{
	vector<unsigned long> returnValue;
	return returnValue;
}
