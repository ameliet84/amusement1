CC=gcc
CFLAGS= -Wall -Werror -Wextra -iquote includes
SDIR= srcs/
INCL= 
EXEC = test
SRCS= 	btree_level_count.c\
int ft_strcmp.c\
int btree_insert_data.c\
void btree_apply_by_level.c\
	
OBJ= $(SRCS:.c=.o)


.PHONY:	all clean fclean re mclean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $? $(CFLAGS)

%.o :	$(SDIR)%.c $(INCL)
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -f	$(OBJ)
