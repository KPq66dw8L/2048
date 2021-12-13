all: main

main-noSDL.o: main-noSDL.c functions.h
			  gcc -c main-noSDL.c -ggdb

functions.o: functions.c functions.h
			 gcc -c functions.c -ggdb

main: main-noSDL.o functions.o
	  gcc main-noSDL.o functions.o -o main -ggdb

clean:
		rm* .o
		rm main