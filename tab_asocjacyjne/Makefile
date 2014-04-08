PROG=bench


__start__: obj ${PROG} 
	./${PROG} 
obj:
	mkdir obj

${PROG}:   obj/stos_tablica.o obj/main.o 
	g++ -Wall -o ${PROG} obj/stos_tablica.o obj/main.o

obj/main.o:  src/main.cpp inc/stos_tablica.hh
	g++  -Wall -pedantic -Iinc -c src/main.cpp -o obj/main.o
obj/stos_tablica.o: src/stos_tablica.cpp  inc/stos_tablica.hh
	g++ -Wall -pedantic -Iinic -c src/stos_tablica.cpp -o obj/stos_tablica.o

clean:
	rm -f ${PROG} obj/*
