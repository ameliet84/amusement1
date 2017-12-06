#include "ft_sort_integer_table.h"
#include <stdio.h>
#include <time.h>
int rand_a_b(int a, int b)
{
	return rand()%(b-a) +a;
}

int main(void)
{
int size=8, i;

int tab[size];
srand(time(NULL));

for (i=0;i<size;i++)
{
tab[i]=rand_a_b(0, 10);
printf("%d \n", tab[i]);
}

ft_sort_integer_table(&tab[0], size);

printf("deuxième tableau\n");

for (i=0; i<size; i++)
{
printf("%d \n", tab[i]);
}
return 0;
}


