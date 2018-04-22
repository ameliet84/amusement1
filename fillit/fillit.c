#include "fillit.h"

int count = 0;


int read_trios(char ***tab, int fd, char a, int i)
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
			ft_strcpy(src, str, 0);
			if (treat_trio(a, str, &n) == 0)
				return 0;
			else
				ft_strcpy(str, tab[i][++p], -1);
			if( src[3] != '\n' || (p == 3 && test_trio(tab[i]) == 0))
				return 0;
		}
	return ( p != 3) ? 0 : i+1;
}

int fill_tab(char **table, char ***tab, int size, int i)
{
	count ++;
	if(count %1000000 == 0)
		printf("count = %d\n", count);
	int pos;
	int len;

	len = length(table);
	pos = -1;
//	print_tab(table, len);
	if(i == size)
		return 1;
	while(++pos<len*len)
	{
//		if(caractere(tab[i]) == 'G')
//				printf("ok et pos= %d \n", pos);
		if(test_piece(table, tab[i], pos, len) == 1)
		{
			place_piece(table, tab[i], pos, len);
			if(fill_tab(table, tab, size, i+1) == 1)
			{
			//	pos = 0;
				return 1;
			}
//		while(pos<len*len-1 && test_piece(table, tab[i], pos, len)==0)
//		{
//			printf("pos = %d et char = %c et test = %d\n", pos, caractere(tab[i]), test_piece(table, tab[i], pos, len));
//			pos++;
//		}
		}
	remove_piece(table, tab[i], len);
//	pos++;
	}
	return 0;
}

void fill_it(char ***tab, int size, int i)
{
	char **table;

	printf("square = %d et size = %d\n",square((size+i)*4), size+i);
	table = create_tab(square((size+i)*4));
	init_table(table, square((size+i)*4));
	if(fill_tab(table, tab, size, 0)==0)
	{
		free(table);
		fill_it(tab, size, i+1);
	}
	else
	{
	//	treat_tab(table, length(table));
		print_tab(table, length(table));
		free(table);
	}
}

int main(int argc, char **argv)
{
	int test;
	char ***tab;
	int i;
	int j;

	i =-1;
	tab=malloc(sizeof(char **)*26);
	while(++i<26)
		tab[i] = malloc(sizeof(char *)*4);
	i = -1;
	while(++i<26)
	{
		j = -1;
		while (++j<4)
			tab[i][j] = malloc(sizeof(char)*4);
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