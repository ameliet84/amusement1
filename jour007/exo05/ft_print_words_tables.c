#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char **ft_split_whitespaces(char *str);

void ft_print_words_tables(char **tab)
{

int i=0, j=0;

while (tab[i][j])
{
	while(tab[i][j])
	{
	ft_putchar(tab[i][j]);
	j++;
	}
	ft_putchar('\n');
	j=0;
	i++;
}
}

int	main(int argc, char **argv)
{
if (argc==2)
{
	ft_print_words_tables(ft_split_whitespaces(argv[1]));
}
return 0;
}	
	
