CC = gcc

CFLAGS =  -g

TARGET = main

OBJ = main.o jogador.o pilha.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c jogador.h pilha.h
	$(CC) $(CFLAGS) -c main.c

jogador.o: jogador.c jogador.h
	$(CC) $(CFLAGS) -c jogador.c

pilha.o: pilha.c pilha.h jogador.h
	$(CC) $(CFLAGS) -c pilha.c

run: all
	./$(TARGET)
