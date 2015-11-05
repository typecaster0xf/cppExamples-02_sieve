CC=g++

.SECONDEXPANSION:
OBJECT=$(CC) $< -c -I include -o $@
OPTIMIZED=$(CC) $< -c -I include -O2 -D NDEBUG -o $@
UNIT_TEST=$(CC) $< -c -I include -D UNITTEST -o $@
LINK=$(CC) $^ -o $@

#################################################

unittestSieve.exe: bin/sieve__ut.o
	$(LINK)

#################################################

bin/seive.o: src/sieve.cpp include/sieve.h | bin
	$(OBJECT)
bin/sieve__opt.o: src/sieve.cpp include/sieve.h | bin
	$(OPTIMIZED)
bin/sieve__ut.o: src/sieve.cpp include/sieve.h | bin
	$(UNIT_TEST)

bin:
	mkdir bin

.PHONY: clean
clean:
	rm -rf bin
