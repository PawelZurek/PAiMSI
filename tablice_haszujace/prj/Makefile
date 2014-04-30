PROG=tab_hash


__start__: obj ${PROG} 
	./${PROG} 
obj:
	mkdir obj

${PROG}:   obj/tab_hash.o obj/main.o 
	g++ -Wall -o ${PROG} obj/tab_hash.o obj/main.o

obj/main.o:  src/main.cpp inc/tab_hash.hh
	g++  -Wall -pedantic -Iinc -c src/main.cpp -o obj/main.o
obj/tab_hash.o: src/tab_hash.cpp  inc/tab_hash.hh
	g++ -Wall -pedantic -Iinic -c src/tab_hash.cpp -o obj/tab_hash.o

clean:
	rm -f ${PROG} obj/*
