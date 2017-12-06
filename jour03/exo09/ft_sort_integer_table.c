#include "ft_sort_integer_table.h"

void ft_sort_integer_table(int *tab, int size)
{
int i, j, temp;
for (i=0; i<size-1; i++)
{
	for(j=i+1; j<size;j++)
	{
		if (tab[j]<tab[i])
		{
		temp=tab[i];
		tab[i]=tab[j];
		tab[j]=temp;
		}
	}
}
}
