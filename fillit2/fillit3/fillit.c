#include "fillit.h"

int count = 0;


int read_trios(t_piece ***tab, int fd)
{
	char str[20];
	int k;
	int i;
	int n;
	int j;

	k = 0;
	while(read(fd, str, 20) > 0)
	{
		n =0;
		i = -1;
		j = 0;
		while(++i<19)
		{
			if((i+1)%5 == 0 && str[i] != '\n')
				return 0;
			else if((i+1)%5 == 0)
			{
				++j;
				++i;
			}
			if(str[i] == '#')
			{
				++n;
				tab[k][(i-j)/4][(i-j)%4].car = 'A' + k;
			}
			else if(str[i] == '.')
				tab[k][(i-j)/4][(i-j)%4].car = '.';
			else
				return 0;
		}
		if(n != 4 || test_trio(tab[k]) == 0 || (read(fd, str, 1) >0 && str[0] != '\n'))
			return 0;
		treat_trio2(tab[k], k);
		++k;
	}
	return k;
}

/*
int read_trios(t_piece ***tab, int fd, char a, int i)
{
	int p;
	int n;
	char str[4];
	char src[3];

	p = -1;
	n = 0;
	while(read(fd, str, 1)>0)
		if (p == 3 && str[0]!= '\n')
			return 0;
		else if(str[0] == '\n')
			return ( p != 3 || n!=4)? 0 : read_trios(tab, fd, a+1, i+1);
		else
		{
			read(fd, src, 4);
			ft_strcpy(src, str);
			if (treat_trio(a, str, &n) == 0)
				return 0;
			else
				ft_strcpy2(str, tab[i][++p]);
			if( src[3] != '\n' || (p == 3 && test_trio(tab[i]) == 0))
				return 0;
			if(p == 3)
				treat_trio2(tab[i], i);
		}
	return ( p != 3) ? 0 : i+1;
}
*/
int fill_tab(char **table, t_piece ***tab, int size, int k)
{
	int i;
	int len;
	int j;
	int maxi;
	int maxj;

	maxi = tab[k][0][0].maxi;
	maxj = tab[k][0][0].maxj;
	len = length(table);
	i = -1;
	if(k == size)
		return 1;
	while(++i <= len - maxi)
	{
		j = -1;
		while(++j<=len - maxj)
		{	
			if(test_piece(table, tab[k], i, j) == 1)
			{
				place_piece(table, tab[k], i, j);
				if(fill_tab(table, tab, size, k+1) == 1)
					return 1;
				remove_piece(table, tab[k], i, j);
			}
		}
	}
	return 0;
}

void fill_it(t_piece ***tab, int size)
{
	char **table;
	int len;
	int i;

	i = 0;
	len = square((size)*4);
	table = create_tab(len);
	init_table(table, len);
	while(fill_tab(table, tab, size, 0)==0)
	{
		free(table);
		printf("square = %d et size = %d\n",square((size+i)*4), size+i);
		++i;
		len = square((size+i)*4);
		table = create_tab(len);
		init_table(table, len);
	}
		print_tab(table, len);
		free(table);
}

int main(int argc, char **argv)
{
	int test;
	t_piece ***tab;
	int i;
	int j;

	i =-1;
	tab=malloc(sizeof(t_piece **)*26);
	while(++i<26)
		tab[i] = malloc(sizeof(t_piece *)*4);
	i = -1;
	while(++i<26)
	{
		j = -1;
		while (++j<4)
			tab[i][j] = malloc(sizeof(t_piece)*4);
	}
	test = (argc == 2) ? read_trios(tab, open(argv[1], O_RDONLY)): read_trios(tab, 0);
	print_tab2(tab, test);
	if(test == 0)
		write(1, "error\n", 6);
	else
		fill_it(tab, test);
	free(tab);		
	return 0;
}