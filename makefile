CC = gcc
CFLAGS = -Wall -g

#
main: main.o array_poly.o poly.o util.o
	$(CC) -o main main.o array_poly.o poly.o util.o

array_poly.o: array_poly.c
	$(CC) $(CFLAG) -c array_poly.c

poly.o: poly.c
	$(CC) $(CFLAG) -c poly.c

util.o: util.c
	$(CC) $(CFLAG) -c util.c

clean:
	rm -rf main *.o *.exe 
#	del *.o *.exe