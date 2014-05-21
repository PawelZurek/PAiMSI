PROG=simplex


__start__: obj ${PROG} 
	./${PROG} 
obj:
	mkdir obj

${PROG}:   obj/main.o obj/simplex.o 
	g++ -Wall -o ${PROG} obj/main.o obj/simplex.o
 
obj/main.o:  src/main.cpp inc/simplex.hh
	g++  -Wall -pedantic -Iinc -c src/main.cpp -o obj/main.o
obj/simplex.o: src/simplex.cpp  inc/simplex.hh
	g++ -Wall -pedantic -Iinic -c src/simplex.cpp -o obj/simplex.o

clean:
	rm -f ${PROG} obj/*
