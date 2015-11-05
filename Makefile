CC=g++

.SECONDEXPANSION:
OBJECT=$(CC) $< -c -I include -o $@
OPTIMIZED=$(CC) $< -c -I include -O2 -march=native -D NDEBUG -o $@
UNIT_TEST=$(CC) $< -c -I include -D UNITTEST -o $@
LINK=$(CC) $^ -o $@

#################################################

sieve.exe: bin/main__opt.o bin/sieve__opt.o
	$(LINK)

sieve-dev.exe: bin/main.o bin/sieve.o
	$(LINK)

##########

unittestSieve.exe: bin/sieve__ut.o
	$(LINK)

#################################################

bin/main.o: src/main.cpp include/sieve.h | bin
	$(OBJECT)
bin/main__opt.o: src/main.cpp include/sieve.h | bin
	$(OPTIMIZED)

bin/sieve.o: src/sieve.cpp include/sieve.h | bin
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
	rm -r *.exe
