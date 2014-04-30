PROG=grafy


__start__: obj ${PROG} 
	./${PROG} 
obj:
	mkdir obj

${PROG}:   obj/main.o obj/graf.o
	g++ -Wall -o ${PROG} obj/main.o obj/graf.o
 
obj/main.o:  src/main.cpp inc/graf.hh 
	g++  -Wall -pedantic -Iinc -c src/main.cpp -o obj/main.o
obj/graf.o: src/graf.cpp  inc/graf.hh
	g++ -Wall -pedantic -Iinic -c src/graf.cpp -o obj/graf.o
clean:
	rm -f ${PROG} obj/*
