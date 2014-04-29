PROG=bench


__start__: obj ${PROG} 
	./${PROG} 
obj:
	mkdir obj

${PROG}:   obj/kolejka_tablica.o obj/kolejka_lista.o obj/stos_tablica.o obj/stos_lista.o obj/main.o obj/benchmark.o 
	g++ -Wall -o ${PROG} obj/kolejka_tablica.o obj/kolejka_lista.o obj/stos_tablica.o obj/stos_lista.o obj/main.o obj/benchmark.o

obj/main.o:  src/main.cpp inc/benchmark.hh
	g++  -Wall -pedantic -Iinc -c src/main.cpp -std=c++11 -o obj/main.o
obj/kolejka_tablica.o: src/kolejka_tablica.cpp  inc/kolejka_tablica.hh
	g++ -Wall -pedantic -Iinic -c src/kolejka_tablica.cpp -o obj/kolejka_tablica.o
obj/stos_tablica.o: src/stos_tablica.cpp  inc/stos_tablica.hh
	g++ -Wall -pedantic -Iinic -c src/stos_tablica.cpp -o obj/stos_tablica.o
obj/stos_lista.o: src/stos_lista.cpp  inc/stos_lista.hh
	g++ -Wall -pedantic -Iinic -c src/stos_lista.cpp -o obj/stos_lista.o
obj/kolejka_lista.o: src/kolejka_lista.cpp  inc/kolejka_lista.hh
	g++ -Wall -pedantic -Iinic -c src/kolejka_lista.cpp -o obj/kolejka_lista.o
obj/benchmark.o: src/benchmark.cpp inc/benchmark.hh 
	g++  -Wall -pedantic -Iinic -c src/benchmark.cpp -o obj/benchmark.o

clean:
	rm -f ${PROG} obj/*
