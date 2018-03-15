#include"do_op.h"
int	length(char *str)
{ 
	int	i;

	i=0;
	while(str[i])
		i++;
	return i;
}

int ft_atoi(char *str)
{
	int nbr;
	int pwr;

	nbr=0;
	pwr=1;
	while((*str>=1 && *str<=13) || *str==32)
		str++;
	if(*str=='+' || *str=='-')
		str++;
	while(*str>='0' && *str<='9')
		str++;
	str--;
	while(*str>='0' && *str<='9')
	{
		nbr=nbr+(*str-'0')*pwr;
		pwr*=10;
		str--;
	}
	if(*str=='-')
		return -nbr;
	return nbr;
}

void	ft_putnbr(int nb)
{
	char *base="0123456789";
	if(nb<0)
	{
		nb*=-1;
		write(1, "-", 1);
	}
	if (nb/10>0)
		ft_putnbr(nb/10);
	write(1, base +nb%10, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i=-1;
	if (length(s1)!=length(s2))
		return 1;
	while(s1[++i])
		if(s1[i]!=s2[i])
			return 1;
	return 0;
}

int elt(int a)
{
	int i;
	int power;

	i=0;
	power=1;
	while(a/power>0)
	{
		i++;
		power*=10;
	}
	return i;
}

int puissance(int a)
{
	int nb;

	nb=1;
	while(--a>=0)
		nb=nb*10;
	return nb;
}

void do_stuff(char *nombre, int i, int nb, int b)
{
	while(++i<nb+1)
		{
			nombre[i]='0'+b/puissance(nb-i);
			b=b%puissance(nb-i);
		}
}

char *nbr(int a)
{
	char *nombre;
	
	if(a==0)
		nombre="0";
	else
	{
		if(a<0)
		{
			nombre=malloc(sizeof(char)*elt(-a));
			nombre[0]='-';
			do_stuff(nombre, 0, elt(-a), -a);
		}
		else
		{
			nombre=malloc(sizeof(char)*elt(a)-1);
			do_stuff(nombre, -1, elt(a)-1, a);
		}
	}
	return nombre;
}

void fusion(char *s1, char *s2, int m, int n)
{
	int i;
	int j;
	i=-1;
	j=0;
	while(++i<length(s2))
		s1[m+i]=s2[i];
	while(n+j<length(s1))
	{
		s1[m+i]=s1[n+j];
		i++;
		j++;
	}
	s1[m+i]='\0';
}

void skip(char *str, int i)
{
	int j;

	j=i-1;
	while(++j<length(str))
		str[j]=str[j+1];
	str[j]='\0';
}

void split_white(char *str)
{
	int i;

	i=-1;
	while(++i<length(str))
	{
		if(str[i]==' ')
			skip(str, i);
	}
}
