#!/bin/sh

make unittestSieve.exe
./unittestSieve.exe

echo ""

make sieve.exe
./sieve.exe 100 primes.txt
cat primes.txt
