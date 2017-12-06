#include <stdio.h>

void ft_swap(int *a, int *b)
{
int temp= *a;
*a = *b;
*b = temp;
}

int main(void)
{
int a=12, b =65;
ft_swap(&a,&b);
printf("a est %d, et b est %d \n",a,b);
return 0;
}
