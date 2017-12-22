#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}



int	nb_lines(int size)
{
int	lines;
	lines = (size+2)*(size+3)/2-3;
return lines;
}



int 	nb_spaces(int line, int size)
{
int	count_floor, spaces, floor;
	count_floor =3;
	spaces=0;
	floor=3;

	while (line<nb_lines(size))
	{ 	
		if (line>count_floor)
		{
			++floor;
			count_floor+=floor;
		}
		else
		{	
			if (line<count_floor)
				spaces+=1;

			if (line==count_floor)
			{
				spaces+=3;
				++floor;
				count_floor+=floor ;
			}
			++line;
		}
	}
return spaces;
}

int	nb_stars(int line)
{
	int 	i, count_floor, stars, floor;
		count_floor=3;
		stars=1;
		floor=3;
		i=1;

	while (i<line)
	{
		if (i<count_floor)
			stars+=2;
		if (i==count_floor )
		{
			stars+=6;
			++floor;
			count_floor+=floor;
		}
		++i;
	}
return stars;
}



void	print_line(int line, int size)
{
	int	i;
		i=0;
	while (i<nb_spaces(line, size))
	{
		ft_putchar(' ');
		++i;
	}

	ft_putchar('/');

	i=1;

	while (i<=nb_stars(line))
	{
		ft_putchar('*');
		++i;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}
		

void sastantua(int size)
{
	int	line;
		line=1;

	while (line<=nb_lines(size))
	{
		print_line(line, size);
		++line;
	}
}



int main(void)
{
sastantua(7);
return 0;
}
