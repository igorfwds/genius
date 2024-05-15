all: main

main: main.c genius.c
	gcc main.c genius.c -o main

genius.c: genius.c
	gcc -c genius.c

clean:
	rm -f *.o main
