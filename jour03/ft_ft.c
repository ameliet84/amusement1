#include <stdio.h>

void ft_ft(int *nbr);

int main(void)
{
int nbr=13;
ft_ft(&nbr);
printf("%d", nbr);
return 0;
}

void ft_ft(int *nbr)
{
*nbr=42;
}

