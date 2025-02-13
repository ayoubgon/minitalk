CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME_S = server
NAME_C = client

COMM_SRC = includes/ft_atoi.c ft_printf/ft_putadr.c ft_printf/ft_printf.c \
			ft_printf/ft_putchar.c ft_printf/ft_putfunn.c ft_printf/ft_puthex.c \
			ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/ft_putunsignednbr.c
SRC_S = server.c
SRC_C = client.c


COMM_OBJ = $(COMM_SRC:.c=.o)
OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)


%.o: %.c minitalk.h
	@ $(CC) $(FLAGS) -o $@ -c $<

all: client server

server: $(OBJ_S) $(COMM_OBJ)
	@ $(CC) $(FLAGS) $(COMM_OBJ) $(OBJ_S) -o $(NAME_S)

client: $(OBJ_C) $(COMM_OBJ)
	@ $(CC) $(FLAGS) $(COMM_OBJ) $(OBJ_C) -o $(NAME_C)

clean:
	@ $(RM) $(OBJ_S) $(OBJ_C)  $(COMM_OBJ)

fclean: clean
	@ $(RM) $(NAME_S) $(NAME_C)

re: clean all

.PHONY: clean