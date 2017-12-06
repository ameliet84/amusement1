#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod)
{
*div=a/b;
*mod=a%b;
}

int main(void)
{
int a=145, b=6;
int div = 42, mod=42;
ft_div_mod(a, b, &div, &mod);
printf("la division donne %d et le reste est %d \n", div, mod);
return 0;
}
