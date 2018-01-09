#include<unistd.h>

typedef enum t_bool t_bool;
enum t_bool
{
	FALSE,
	TRUE
};

#define EVEN(nbr) ((nbr%2!=0)?0:1)

#define EVEN_MSG "j'ai un nombre pair d'arguments\n"
#define ODD_MSG "j'ai un nombre impair d'arguments\n"

#define SUCCESS 0
