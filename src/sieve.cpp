#include <cassert>
#include <cmath>
#include "sieve.h"


#include <iostream>
using namespace std;




unsigned long findNextPrime(const unsigned long currentPrime,
		const vector<bool> &sieve);

vector<unsigned long> getValuesFromSieve(const vector<bool> &sieve);

unsigned long countValuesInSieve(const vector<bool> &sieve);

//===============================================

Eretosthenes::Eretosthenes(const unsigned long maxValueInSieve):
sieve(maxValueInSieve >> 1, true),
sieveHasNotBeenRun(true)
{}

vector<unsigned long> 
Eretosthenes::runSieve()
{

cout << "Sieve: ";
for(unsigned long j = 0; j < sieve.size(); j++)
cout << sieve[j];
cout << endl;




	if(sieveHasNotBeenRun)
	{
		const unsigned long sievingLimit = static_cast<unsigned long>(
				ceil(sqrt((sieve.size() << 1) | 1)));
	
cout << "sieving limit: " << sievingLimit << endl;
		sieve[0] = false;
		for(unsigned long prime = 3; prime < sievingLimit;
				prime = findNextPrime(prime, sieve))
		{
cout << "Prime to Sieve: " << prime << endl;
			for(unsigned long j = (prime >> 1) + prime;
					j < sieve.size(); j += prime)
{
				sieve[j] = false;
cout << "Falsed: " << j << " : " << ((j << 1) | 1) << endl;
}
		}
		
		sieveHasNotBeenRun = false;
	}
	
	return getValuesFromSieve(sieve);
}

//===============================================

unsigned long findNextPrime(const unsigned long currentPrime,
		const vector<bool> &sieve)
{
cout << "Current Prime: " << currentPrime << endl;
	for(unsigned long j = (currentPrime >> 1) + 1;
			j < sieve.size(); j++)
{
cout << "J val: " << j << " : " << ((j << 1) | 1) << endl;
		if(sieve[j])
			return (j << 1) | 1;
}
	
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

#ifdef UNITTEST
#include <iostream>

using namespace std;

int main()
{
	Eretosthenes primeGenerator(20);
	
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
	
	assert(primes.size() == 8);
	
	cout << "class Eretosthenes unit test passed." << endl;
	return 0;
}
#endif
