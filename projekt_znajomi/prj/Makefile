PROG=grafy


__start__: obj ${PROG} 
	./${PROG} 
obj:
	mkdir obj

${PROG}:   obj/main.o obj/Dijkstry.o 
	g++ -Wall -o ${PROG} obj/main.o obj/Dijkstry.o 
obj/main.o:  src/main.cpp inc/Dijkstry.hh
	g++  -Wall -pedantic -Iinc -c src/main.cpp -o obj/main.o
obj/Dijkstry.o: src/Dijkstry.cpp  inc/Dijkstry.hh
	g++ -Wall -pedantic -Iinic -c src/Dijkstry.cpp -o obj/Dijkstry.o

clean:
	rm -f ${PROG} obj/*
