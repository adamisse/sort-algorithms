# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

# Nome do executável
TARGET = main

# Arquivos fonte
SRCS = main.c callbackUtils.c elementarySorts.c mergeSort.c quickSort.c

# Arquivos objeto gerados a partir dos fontes
OBJS = $(SRCS:.c=.o)

# Regras de compilação
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove arquivos objeto e o executável
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean