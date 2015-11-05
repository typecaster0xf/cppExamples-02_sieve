#include <cassert>
#include <cmath>
#include "sieve.h"

unsigned long findNextPrime(const unsigned long currentPrime,
		const vector<bool> &sieve);

//===============================================

Eretosthenes::Eretosthenes(const unsigned long maxValueInSieve):
sieve(maxValueInSieve >> 1, true),
sieveHasBeenRun(false)
{}

vector<unsigned long> 
Eretosthenes::runSieve()
{
	const unsigned long sievingLimit = static_cast<unsigned long>(
			ceil(sqrt((sieve.size() << 1) | 1)));
	
	for(unsigned long prime = 3; prime < sievingLimit;
			prime = findNextPrime(prime, sieve))
	{
		for(unsigned long j = prime - 1, inc = prime >> 1;
				j < sieve.size(); j += inc)
			sieve[j] = false;
	}
	
	//TODO
	vector<unsigned long> returnValue;
	return returnValue;
}

//===============================================

unsigned long findNextPrime(const unsigned long currentPrime,
		const vector<bool> &sieve)
{
	for(unsigned long j = currentPrime >> 1; j < sieve.size(); j++)
		if(sieve[j])
			return (j << 1) | 1;
	
	assert(false);
}
