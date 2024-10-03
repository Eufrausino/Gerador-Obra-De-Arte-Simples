EXEC = programa
CC = gcc
CFLAGS = -Wall -g
OBJ = obraDeArte.o exibicao.o

all: $(EXEC)
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

obraDeArte.o: obraDeArte.c obraDeArte.h
	$(CC) $(CFLAGS) -c obraDeArte.c

exibicao.o: exibicao.c obraDeArte.h
	$(CC) $(CFLAGS) -c exibicao.c

run: $(EXEC)
	./$(EXEC)
	rm -f $(EXEC)

clean:
	rm -f $(OBJ) $(EXEC)
