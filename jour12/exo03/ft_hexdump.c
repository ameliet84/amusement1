#include "ft_hexdump.h"


void print_position(int position)
{
	int pwr;

	pwr=7;
	if(position==0)
		write(1, "00000000", 8);
	else
	{
		while(position/power(pwr--)<1)
			write(1, "0", 1);
		print_hexa(position);
	}
	write(1," ",1);
}

void print_hex_char(char *str, int size)
{
	int i;

	i=0;
	while(i<size)
	{
		if(i%8==0)
			write(1," ",1);
		if((int)str[i]<16)
				write(1, "0", 1);
		print_hexa((int)str[i++]);
		write(1, " ", 1);
	}
	i--;
	while(++i<16)
	{
		if(i%8==0)
			write(1, " ",1);
		write(1, "   ",3);
	}
}

void print_str(char *str)
{
	int i;

	i=-1;
	write(1, " |", 2);
	while(str[++i])
		print_char(str[i]);
	write(1, "|", 1);
	while(++i<16)
		write(1, " ",1);
	write(1, "\n", 1);

}

void put_str(char *s1, char *s2, int position)
{
	int i;

	i=0;
	while(s2[i+position] && i<16)
	{
		s1[i]=s2[i+position];
		i++;
	}
	s1[i]='\0';
}

void ft_hexdump(char *str, int size)
{
	int i;
	int position;
	char *s1;
	int size_char;

	i=0;
	s1=malloc(sizeof(char)*16+1);
	while(i<size)
	{
		position=i;
		if(size-position>=16)
			size_char=16;
		else
			size_char=size-position;
		print_position(position);
		put_str(s1, str, position);
		print_hex_char(s1, size_char);
		print_str(s1);
		i+=16;
	}
	if(size_char<16)
	{
		print_position(position+size_char);
		write(1, "\n",1);
	}
}

int main(int argc, char **argv) 
{
	if(argc>1)
	{
		ft_hexdump(all(size_all(argc, argv), argc, argv), size_all(argc, argv));
	}
	return 0;
}


