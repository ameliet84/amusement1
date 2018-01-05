#include<unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
int	i, j;
	i=1;
	j=0;
while (i<argc)
{
	while(argv[i][j])
	{
		ft_putchar(argv[i][j]);
		++j;
	}
	write(1, "\n", 1);
	++i;
	j=0;
}
return 0;
}
	
