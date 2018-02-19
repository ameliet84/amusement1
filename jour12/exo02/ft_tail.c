#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void ft_tail(char *str, int octets)
{
	int size;
	int fd;
	int	i;
	char c;

	i=-1;
	size=0;
	fd=open(str, O_RDONLY);
	while(read(fd, &c, 1)>0)
		size++;
	close(fd);
	fd=open(str, O_RDONLY);
	while(++i<size-octets)
		read(fd, &c, 1);
	while(++i<size)
		while(read(fd, &c, 1)>0)
			write(1, &c, 1);
	write(1, "\n",1);
}

int test(char *str)
{
		if(str[0]!='-' || str[1]!= 'c')
			return 0;
		int i;
		i=2;
		while(str[i])
		{
			if(str[i]<'0' || str[i]>'9')
				return 0;
			i++;
		}
			if(str[2])
				return 2;
		return 1;
}

int place(int argc, char **argv)
{
	int i;

	i=-1;
	while(++i<argc)
	{
		if(test(argv[i])!=0)
			return i;
	}
	return 0;
}

void print_header(char *str)
{
			write(1, "==>", 3);
			while(*str)
			{
				write(1, str, 1);
				str++;
			}
			write(1, "<==\n",4);
	
}

int ft_atoi(char *str)
{
	int pwr;
	int nbr;
	int temp;
	int i;

	pwr=1;
	nbr=0;
	i=0;
	while(str[i]<'0' || str[i]>'9')
		i++;
	temp=i;
	while(str[i++])
		pwr*=10;
	pwr/=10;
	while(str[temp])
	{
		nbr+=(str[temp++]-48)*pwr;
		pwr/=10;
	}
	return nbr;
}

int octet(int test, int tar, char **argv)
{
	if(test==1)
		return ft_atoi(argv[tar+1]);
	else
	{
		return ft_atoi(argv[tar]);
	}
}

int main(int argc, char **argv)
{
	int tar;
	int k;
	int octets;

	tar=place(argc, argv);
	k=test(argv[tar]);
	octets=octet(k, tar, argv);
	if(argc==4 && k==1) 
	{
		if(tar==1)
			ft_tail(argv[3], octets);
		else
			ft_tail(argv[1], octets);
	}
	else if(argc==3)
	{
		if(tar==1)
			ft_tail(argv[2], octets);
		else
			ft_tail(argv[1], octets);
	}
	else 
	{
		int i;

		i=0;
		while(++i<tar)
		{
			print_header(argv[i]);
			ft_tail(argv[i], octets);
		}
		i++;
		if(k==1)
			i++;
		while(i<argc)
		{
			print_header(argv[i]);
			ft_tail(argv[i], octets);
			i++;
		}
	}
	return 0;
}