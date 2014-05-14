PROG=grafy


__start__: obj ${PROG} 
	./${PROG} 
obj:
	mkdir obj

${PROG}:   obj/main.o obj/graf.o obj/stos_lista.o obj/kolejka_lista.o obj/benchmark.o
	g++ -Wall -o ${PROG} obj/main.o obj/graf.o obj/stos_lista.o obj/kolejka_lista.o obj/benchmark.o
 
obj/main.o:  src/main.cpp inc/graf.hh inc/stos_lista.hh
	g++  -Wall -pedantic -Iinc -c src/main.cpp -o obj/main.o
obj/graf.o: src/graf.cpp  inc/graf.hh
	g++ -Wall -pedantic -Iinic -c src/graf.cpp -o obj/graf.o
obj/stos_lista.o: src/stos_lista.cpp  inc/stos_lista.hh
	g++ -Wall -pedantic -Iinic -c src/stos_lista.cpp -o obj/stos_lista.o
obj/kolejka_lista.o: src/kolejka_lista.cpp  inc/kolejka_lista.hh
	g++ -Wall -pedantic -Iinic -c src/kolejka_lista.cpp -o obj/kolejka_lista.o
obj/benchmark.o: src/benchmark.cpp  inc/benchmark.hh
	g++ -Wall -pedantic -Iinic -c src/benchmark.cpp -o obj/benchmark.o
clean:
	rm -f ${PROG} obj/*
