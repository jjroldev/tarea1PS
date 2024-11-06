CC = gcc
CFLAGS = -Wall -g
OBJS = main.o datos.o calculos.o
ASM = main.s datos.s calculos.s
DATA_FILE = usuarios.txt

all: programa

programa: $(OBJS)
	$(CC) -o programa $(OBJS) -lm

main.o: main.c utils.h
	$(CC) $(CFLAGS) -c main.c

datos.o: datos.c utils.h
	$(CC) $(CFLAGS) -c datos.c

calculos.o: calculos.c utils.h
	$(CC) $(CFLAGS) -c calculos.c

%.s: %.c
	$(CC) -S $(CFLAGS) $< -o $@

%.s: %.o
	objdump -d $< > $@

clean:
	rm -f *.o *.s programa
