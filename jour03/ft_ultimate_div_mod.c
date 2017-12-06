#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b)
{
int temp1 = *a;
*a=*a / *b;
*b= temp1% *b;
}

int main(void)
{
int a=56, b=13;

ft_ultimate_div_mod(&a,&b);

printf("la division donne %d, le reste est %d \n", a, b);
return 0;
}
