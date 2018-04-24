#include "fillit.h"

int count = 0;


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

int fill_tab(char **table, t_piece ***tab, int size, int k)
{
	count ++;
	if(count %1000000 == 0)
	{
		printf("count = %d\n", count);
		return 1;
	}
	int i;
	int len;
	int j;
	int maxi;
	int maxj;

	maxi = tab[k][0][0].maxi;
	maxj = tab[k][0][0].maxj;
//	print_tab(table, length(table));
	len = length(table);
	i = -1;
	if(k == size)
		return 1;
	while(++i <= len - maxj)
	{
		j = -1;
//		while(test_tab1(table, i, j, size) == 0 || test_tab2(table, i, j, size) == 0)
//			++j;
//		-- j; 
		while(++j<=len - maxi)
		{	
			if(test_piece(table, tab[k], i, j, len) == 1)
			{
	//			if(tab[k][0][0].letter == 'H')
	//				printf("i = %d, j =%d\n",i, j );
				place_piece(table, tab[k], i, j);
				if(fill_tab(table, tab, size, k+1) == 1)
					return 1;
				remove_piece(table, tab[k], i, j, len);
			}

//		if(tab[k][0][0].letter == 'H')
//			printf("i = %d, j =%d\n",i, j);
		}
	}
	return 0;
}

void fill_it(t_piece ***tab, int size, int i)
{
	char **table;
	int len;

	len = square((size+i)*4);
	printf("square = %d et size = %d\n",square((size+i)*4), size+i);
	table = create_tab(len);
	init_table(table, len);
	if(fill_tab(table, tab, size, 0)==0)
	{
		free(table);
		fill_it(tab, size, i+1);
	}
	else
	{
		print_tab(table, len);
		free(table);
	}
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
	test = (argc == 2) ? read_trios(tab, open(argv[1], O_RDONLY), 'A', 0): read_trios(tab, 0, 'A', 0);
	print_tab2(tab, test);
	if(test == 0)
		write(1, "error\n", 6);
	else
		fill_it(tab, test, 0);
	free(tab);		
	return 0;
}