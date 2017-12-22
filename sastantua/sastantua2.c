#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	nb_lines(int size)
{
int	n;
	n=(size+2)*(size+3)/2-3;
return n;
}



int	nb_stars(int line, int floor, int stars, int i)
{
if (i<line && i<nb_lines(floor))
	return nb_stars(line, floor,  stars +2, i+1);

if (i==nb_lines(floor) && i<line)
	return nb_stars(line,floor+1, stars +6, i+1);

return stars;
}



void	print_spaces(int size, int line, int floor, int spaces)
{
int	i;
	i=1;

	if (line<nb_lines(size) && line>nb_lines(floor))
		print_spaces(size, line,floor+1, spaces);
	else if (line<nb_lines(size) && line<nb_lines(floor))
		print_spaces(size, line+1, floor, spaces+1);

	else if (line<nb_lines(size) && line==nb_lines(floor))
		print_spaces(size, line+1, floor+1, spaces+3);

	else
	{
		while (i<=spaces)
		{
			ft_putchar(' ');
			i++;
		}
	}
}


void print_line(int line, int size, int size_door)
{
int	i;
	i=1;	
	print_spaces(size, line, 1, 0);
	ft_putchar('/');	
if (line<=nb_lines(size)-size_door)
	{
		while (i<=nb_stars(line, 1, 1, 1))
		{
			ft_putchar('*');
			++i;
		}
	}
else
	{
		while (i<=(nb_stars(line, 1,1, 1)-size_door)/2)
			{
			ft_putchar('*');
			++i;
			}
		while(i>(nb_stars(line,1,1,1)-size_door)/2 && i<=(nb_stars(line,1,1,1)+size_door)/2)
		{
			if (line==nb_lines(size)-(size_door-1)/2 && i==(nb_stars(line, 1, 1, 1)+size_door)/2-1 && size_door>=5)
			ft_putchar('$');
			else
			ft_putchar('|');
		
			++i;
		}
		while(i<=nb_stars(line,1,1,1))
		{
			ft_putchar('*');
			i++;
		}
	}
ft_putchar('\\');
ft_putchar('\n');
}

void	sastantua(int size)
{
	int	line, size_door, i;
		line=1;
		i=5;
	if (size==1||size==2)
		size_door=1;
	if (size==3||size==4)
		size_door=3;
	if (size>=5)
	{
		size_door=5;
		while (i<size)
		{
			size_door+=2;
			i++;
		}
	}
	
	while(line<=nb_lines(size))
	{
		print_line(line, size, size_door);
		line++;
	}
	
	
}

int main(void)
{
sastantua(7);

return 0;
}
