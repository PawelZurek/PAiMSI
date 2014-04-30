PROG=benchmark


__start__: obj ${PROG} 
	./${PROG} 
obj:
	mkdir obj

${PROG}:   obj/tab_hash.o obj/main.o obj/benchmark.o obj/stos_tablica.o
	g++ -Wall -o ${PROG} obj/tab_hash.o obj/main.o obj/benchmark.o obj/stos_tablica.o
 
obj/main.o:  src/main.cpp inc/tab_hash.hh inc/benchmark.hh inc/drzewo.hh
	g++  -Wall -pedantic -Iinc -c src/main.cpp -o obj/main.o
obj/tab_hash.o: src/tab_hash.cpp  inc/tab_hash.hh
	g++ -Wall -pedantic -Iinic -c src/tab_hash.cpp -o obj/tab_hash.o
obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh 
	g++  -Wall -pedantic -Iinic -c src/benchmark.cpp -o obj/benchmark.o
obj/stos_tablica.o: src/stos_tablica.cpp  inc/stos_tablica.hh
	g++ -Wall -pedantic -Iinic -c src/stos_tablica.cpp -o obj/stos_tablica.o


clean:
	rm -f ${PROG} obj/*
