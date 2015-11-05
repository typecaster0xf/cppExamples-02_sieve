#include <cassert>
#include <cmath>
#include "sieve.h"

/*Combs through the sieve until it finds the next
"true" value and returns the number it
represents.  Used in the sieving outer loop to
update the loop variable.*/
unsigned long findNextPrime(const unsigned long currentPrime,
		const vector<bool> &sieve);

/*Converts the sieve flagging numbers as prime or
composite into a vector of prime numbers.*/
vector<unsigned long> getValuesFromSieve(const vector<bool> &sieve);

/*Used by getValuesFromSieve() to determine how
much space to reserve in memory for its output
vector.*/
unsigned long countValuesInSieve(const vector<bool> &sieve);

//===============================================

Eratosthenes::Eratosthenes(const unsigned long maxValueInSieve):
sieve(maxValueInSieve >> 1, true),
sieveHasNotBeenRun(true)
{}

vector<unsigned long> 
Eratosthenes::runSieve()
{
	if(sieveHasNotBeenRun)
	{
		const unsigned long sievingLimit = static_cast<unsigned long>(
				ceil(sqrt((sieve.size() << 1) | 1)));
	
		sieve[0] = false;
		for(unsigned long prime = 3; prime < sievingLimit;
				prime = findNextPrime(prime, sieve))
		{
			for(unsigned long j = (prime >> 1) + prime;
					j < sieve.size(); j += prime)
				sieve[j] = false;
		}
		
		sieveHasNotBeenRun = false;
	}
	
	return getValuesFromSieve(sieve);
}

//===============================================

unsigned long findNextPrime(const unsigned long currentPrime,
		const vector<bool> &sieve)
{
	for(unsigned long j = (currentPrime >> 1) + 1;
			j < sieve.size(); j++)
		if(sieve[j])
			return (j << 1) | 1;
	
	assert(false);
}

vector<unsigned long> getValuesFromSieve(const vector<bool> &sieve)
{
	vector<unsigned long> primeNumbers;
	primeNumbers.reserve(countValuesInSieve(sieve) + 1);
	
	primeNumbers.push_back(2);
	for(unsigned long j = 0; j < sieve.size(); j++)
		if(sieve[j])
			primeNumbers.push_back((j << 1) | 1);
	
	return primeNumbers;
}

unsigned long countValuesInSieve(const vector<bool> &sieve)
{
	unsigned long values = 0;
	
	for(unsigned long j = 0; j < sieve.size(); j++)
		if(sieve[j])
			values++;
	
	return values;
}

//===============================================

#ifdef UNITTEST
#include <iostream>

using namespace std;

int main()
{
	Eratosthenes primeGenerator(30);
	
	const vector<unsigned long> primes =
			primeGenerator.runSieve();
	
	assert(primes[0] == 2);
	assert(primes[1] == 3);
	assert(primes[2] == 5);
	assert(primes[3] == 7);
	assert(primes[4] == 11);
	assert(primes[5] == 13);
	assert(primes[6] == 17);
	assert(primes[7] == 19);
	assert(primes[8] == 23);
	assert(primes[9] == 29);
	
	assert(primes.size() == 10);
	
	cout << "class Eretosthenes unit test passed." << endl;
	return 0;
}
#endif
