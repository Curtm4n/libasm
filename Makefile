CC = gcc

ASM = nasm

LD = ld

AR = ar

CFLAGS = -f elf64

LDFLAGS = -Llib -lasm -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2

SRC = src/ft_strlen.s	\
		src/ft_strcpy.s \
		src/ft_strcmp.s \
		src/ft_write.s \
		src/ft_read.s

OBJ = $(SRC:.s=.o)

LIBRARY = lib/libasm.a

EXEC = bin/main_test

all: $(LIBRARY)

$(LIBRARY): $(OBJ)
	$(AR) rcs $@ $^

%.o: %.s
	$(ASM) $(CFLAGS) -o $@ $<

test: $(LIBRARY)
	$(CC) -Wall -Wextra -Werror -o bin/main.o -c src/main.c
	$(CC) -Wall -Wextra -Werror -o $(EXEC) bin/main.o $(LDFLAGS)

clean:
	rm -f $(OBJ) bin/main.o

fclean: clean
	rm -f $(LIBRARY) $(EXEC)

re: fclean all

.PHONY: all clean fclean re test


