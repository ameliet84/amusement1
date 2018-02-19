#include "ft_hexdump.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int power(int pwr)
{
	int nbr;

	nbr=1;
	while(pwr-->0)
		nbr*=16;
	return  nbr;
}

void print_hexa(int nb)
{
	char base[]="0123456789abcedf";

	if(nb/16>0)
		print_hexa(nb/16);
	write(1, base + nb%16, 1);
}

int file_size(char *str)
{
	char c;
	int size;
	int fd;

	size=0;
	fd=open(str, O_RDONLY);
	while(read(fd, &c, 1))
		size++;
	return size;
}

char *all(int size, int argc, char **argv)
{
	int i;
	char *str;
	char c;
	int k;
	int fd;

	k=0;
	i=0;
	str=malloc(sizeof(char)*(size+argc-2));
	while(++i<argc)
	{
		fd=open(argv[i], O_RDONLY);
		while(read(fd, &c, 1)>0)
			str[k++]=c;
		str[k++]='\n';
		close(fd);
	}
	str[k]='\0';
	return str;
}

int size_all(int argc, char **argv)
{
	int i;
	int size;

	i=0;
	size=0;
	while(++i<argc)
		size+=file_size(argv[i]);
	return size;	
}

void print_char(char c)
{
	if(c<32)
		write(1, ".", 1);
	else
		write(1, &c, 1);
}
