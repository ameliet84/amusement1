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

/*
int fill_tab(char **table, t_piece ***tab, int size)
{
	count ++;
	int pos2;
	int len;
	int init2[26] = {-1};
	int i;
	int j;
	int k;

	k =0;
	len = length(table);
	while(k < size)
	{
		pos2 = init2[k];
			while(++pos2 <len*len)
			{
					i = pos2/len;
					j = pos2%len;
				if(test_piece(table, tab[k], i, j, len) == 1)
				{
					init2[k] = pos2;
					place_piece(table, tab[k], i, j);
	//					print_tab(table, len);
					++k;
					if(k==size)
						return 1;
					pos2 = -1;
				}
			}
			if(k == 0)
				return 0;
			--k;
			remove_piece(table, tab[k], init2[k]/len, init2[k]%len);
	}
	return 1;
}
*/

int fill_tab(char **table, t_piece ***tab, int size)
{
	int len;
	t_coord init2[26];
	int i;
	int j;
	int k;
	t_coord max;

	i=-1;
	while(++i<26)
	{
		init2[i].x = -1;
		init2[i].y = -1;
	}

	k =0;
	len = length(table);
	while(k < size)
	{
		i = init2[k].x;
		max.x =  tab[k][0][0].maxi;
			while(++i <=len - max.x)
			{
				max.y =  tab[k][0][0].maxj;
				j = init2[k].y;
				while(++j<=len -max.y)
				{
					if(test_piece(table, tab[k], i, j) == 1)
					{
//	count ++;
//	if(count%1000000 == 0)
//	{
//		printf("%d\n", count);
//		return 0;
//	}
						init2[k].x = i;
						init2[k].y = j;
						place_piece(table, tab[k], i, j);
	
//	if(k >11 && len == 8 && table[0][0] == 'A' && table[0][4]=='B' && table[0][7]== 'C' &&table[6][2] == 'F'  && table[7][7] == 'D' && table[3][3] == 'E' && table[5][1] == 'G' && table[1][4] == 'H')//&& table[2][1] == 'I' && table[7][3] == 'J' && table[1][6] == 'K' && table[4][5] == 'M' && table[7][0] == 'N' && table[1][7] == 'O') 
//	if(k == size-2)
//							print_tab(table, len);
						++k;
						if(k==size)
							return 1;
						max.x =  tab[k][0][0].maxi;
						i = -1;
						init2[k].x = -1;
						init2[k].y = -1;
						j = len;
					}
				}
			}
			if(k == 0)
				return 0;
			--k;
			remove_piece(table, tab[k], init2[k].x, init2[k].y);
			if(init2[k].y == len-tab[k][0][0].maxj || test_piece(table, tab[k],init2[k].x, init2[k].y+1) == 0)
				init2[k].y = -1;
			else
				--init2[k].x;
//			print_tab(table, len);
	}
	return 1;
}

void fill_it(t_piece ***tab, int size)
{
	char **table;
	int len;

	len = square((size)*4);
	table = create_tab(len);
	init_table(table, len);
	while(fill_tab(table, tab, size)==0)
	{

		printf("square = %d et size = %d\n",len, size);
		free(table);
		++len;
		table = create_tab(len);
		init_table(table, len);
	}
	//	print_tab(table, len);
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
	test = (argc == 2) ? read_trios(tab, open(argv[1], O_RDONLY), 'A', 0): read_trios(tab, 0, 'A', 0);
	print_tab2(tab, test);
	if(test == 0)
		write(1, "error\n", 6);
	else
		fill_it(tab, test);
	free(tab);		
	return 0;
}