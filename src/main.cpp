#include <cstdlib>
#include <fstream>
#include <iostream>
#include "sieve.h"

using namespace std;

int main(const int argc, const char* argv[])
{
	if(argc < 3)
	{
		cout << "Usage: " << argv[0]
				<< " <max_value> <output_file_name>" << endl;
		return 0;
	}
	
	const unsigned long maxValue       = atoi(argv[1]);
	const char*         outputFileName = argv[2];
	
	//--
	
	Eretosthenes primeGenerator(maxValue);
	vector<unsigned long> primes = primeGenerator.runSieve();
	
	fstream outputFile(outputFileName);
	for(unsigned long j = 0; j < primes.size(); j++)
		outputFile << primes[j] << '\n';
	outputFile.close();
	
	return 0;
}
