CC=gcc
CFLAGS= -Wall -Werror -Wextra -iquote includes
SDIR= srcs/
INCL= includes/do_op.h 
EXEC = eval
SRCS= 	do_op.c \
	ft.c\
	op.c\
	evalexpr.c\
	
OBJ= $(SRCS:.c=.o)


.PHONY:	all clean fclean re mclean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $? $(CFLAGS)

%.o :	$(SDIR)%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -f	$(OBJ)
