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



int	nb_stars(int line, int floor, int nb_floor, int stars, int i)
{
if (i<line && i<floor)
	return nb_stars(line, floor, nb_floor, stars +2, i+1);

if (i==floor && i<line)
	return nb_stars(line,floor+nb_floor+1, nb_floor+1, stars +6, i+1);

return stars;
}



void	print_spaces(int size, int line, int floor, int nb_floor, int spaces)
{
int	i;
	i=1;

	if (line<nb_lines(size) && line>floor)
		print_spaces(size, line, floor+nb_floor+1, nb_floor+1, spaces);
	else if (line<nb_lines(size) && line<floor)
		print_spaces(size, line+1, floor, nb_floor, spaces+1);

	else if (line<nb_lines(size) && line==floor)
		print_spaces(size, line+1, floor+nb_floor+1, nb_floor+1, spaces+3);

	else
	{
		while (i<=spaces)
		{
			ft_putchar(' ');
			i++;
		}
	}
}


void print_normal_line(int line, int size)
{
int	i;
	
	print_spaces(size, line, 3, 3, 0);
	ft_putchar('/');	
	i=1;
	while (i<=nb_stars(line, 3, 3, 1, 1))
	{
		ft_putchar('*');
		++i;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void print_door_line(int line, int size, int size_door)
{
int	i;
	i=1;
print_spaces(size, line, 3, 3, 0);
ft_putchar('/');

	while (i<=(nb_stars(line, 3, 3, 1, 1)-size_door)/2)
		{
		ft_putchar('*');
		++i;
		}
	while(i>(nb_stars(line,3,3,1,1)-size_door)/2 && i<=(nb_stars(line,3,3,1,1)+size_door)/2)
		{
		if (line==nb_lines(size)-(size_door-1)/2 && i==(nb_stars(line, 3, 3, 1, 1)+size_door)/2-1 && size_door>=5)
		ft_putchar('$');
		else
		ft_putchar('|');

		++i;
		}
	while(i<=nb_stars(line,3,3,1,1))
		{
		ft_putchar('*');
		i++;
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
	
	while(line<=nb_lines(size)-size_door)
	{
		print_normal_line(line, size);
		line++;
	}
	while(line<=nb_lines(size))
	{
		print_door_line(line, size, size_door);
		++line;
	}
}

int main(void)
{
sastantua(7);

return 0;
}
