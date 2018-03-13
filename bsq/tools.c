#include "bsq.h"
/*
void print_obs(t_obs *tab, int nb)
{
	int i;

	i=-1;
	while(++i<nb)
	{
		printf("(%d; %d) ", tab[i].ligne, tab[i].colonne);
	}
	printf("\n");
}
*/



void print_tab(t_elt **tab, int line, int col)
{
	int i;
	int j;

	j=-1;
	while(++j<3)
		printf("%c", tab[0][j].car);
	printf("\n");
	i=0;
	while(++i<line)
	{
		j=-1;
		while(++j<col)
			printf("%c", tab[i][j].car);
//			printf("%c-%d-%d", tab[i][j].car, tab[i][j].ligne, tab[i][j].colonne);
	printf("\n");
	}
}

int test_char(char c, t_elt **tab)
{
	int i;

	i=-1;
	while(++i<3)
		if(c==tab[0][i].car)
			return 1;
	return 0;
}

int min(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

void init_numbers(char *file, int *line, int *col)
{
	int  fd;
	int i;
	char *lines;
	char c;

	lines=malloc(sizeof(char *));
	i=0;
	fd=open(file, O_RDONLY);
	while(read(fd, &c, 1)>0 && (c>='0' && c<='9'))
		lines[i++]=c;
	*line=atoi(lines);
	i=1;
	while(read(fd, &c, 1)>0 && c!=13)
		*col=0;
	read(fd, &c, 1);
	while(read(fd, &c, 1)>0  && c!=13)
		(*col)++;
	close(fd);
}
/*
void convert_tab(char **tab1, t_elt **tab, char *init, int line, int col)
{
	int i;
	int j;
	int m;
	int n;

	i=-1;
	while(++i<line)
	{
	j=-1;
		while(++j<col)
		{
			m=1;
			n=0;
			tab[i][j].car=tab1[i][j];
			while(i+m<line)
				if(tab1[i+m][j]==init[0])
				{
					n++;
					m++;
				}
				else
					m=line;
			tab[i][j].ligne=n;
			m=1;
			n=0;
			while(j+m<col)
				if(tab1[i][j+m]==init[0])
				{
					n++;
					m++;
				}
				else
					m=col;
			tab[i][j].colonne=n;
		}
	}
}

int init_tab(char *file, int line, int col, t_obs *tab, char *init)
{
    int  fd;
	int i;
	int j;
	int m;
	char c;
	time_t debut;
	time_t fin;

	m=0;
	fd=open(file, O_RDONLY);
	while(read(fd, &c, 1)>0 &&  c!=10)
		i=0;
		debut=time(NULL);
	while(i<line)
	{
		j=0;
		while( read(fd, &c, 1)>0 && c!=13)
		{
			if(test_char(c, init)==0)
			{
				printf("carte invalide\n");
				return 0;
			}
			if(c==init[1])
			{
				tab[m].ligne=i;
				tab[m].colonne=j;
				m++;
			}
			j++;
		}

		read(fd, &c, 1);
		if(j!=col)
		{
			printf("carte invalide\n");
			return 0;
		}
		i++;
	}
	fin=time(NULL);
	printf("durée fonction=%d secondes\n", (int)(fin-debut));
//	print_tab(tab, line, col);
	close(fd);
	return m;
}

*/

/*
void init_tab(char *file, int line, int col, char **tab, char *init)
{
    int  fd;
	int i;
	int k;
	char c[col];
	time_t debut;
	time_t fin;

	fd=open(file, O_RDONLY);
	while(read(fd, c, 1)>0 && (c[0]>='0' && c[0]<='9'))
	{
		i=0;
	}
	read(fd, c, 4);
	debut=time(NULL);
	while(i<line)
	{
		read(fd, c, col);
		k=-1;
		while(++k<col)
		{
			if(test_char(c[k], init)==0)
			{
				printf("carte invalide\n");
				return;
			}
			tab[i][k]=c[k];
		}
		read(fd, &c, 2);
		i++;
	}
	fin=time(NULL);
	printf("durée fonction=%d secondes\n", (int)(fin-debut));
//	print_tab(tab, line, col);
	close(fd);
}

void convert_tab(t_elt **tab, char *init, int line, int col)
{
	int i;
	int j;
	int m;
	int n;

	i=-1;
	while(++i<line)
	{
		j=-1;
		while(++j<col)
		{
			m=0;
			n=1;
			while(i+n<line)
			{
				if(tab[i+n][j].car==init[0])
					m++;
				else
					n=line;
				n++;
			}
			tab[i][j].colonne=m;
		}
	}	
}
*/

int nb_empty(t_elt **tab, char *c, int col, int j)
{
	int k;
	int m;

	k=1;
	m=0;
	while(++k<col-j)
	{
		if(c[j+k]==tab[0][0].car)
			m++;
		else
			k=col;
	}
	return m;
}

int init_tab(char *file, int line, int col, t_elt **tab)
{
    int  fd;
	int i;
	int k;
	char c[col];

	fd=open(file, O_RDONLY);
	while(read(fd, c, 1)>0 && (c[0]>='0' && c[0]<='9'))
		i=0;
	tab[0][0].car=c[0];
	read(fd, c, 4);
	tab[0][1].car=c[0];
	tab[0][2].car=c[1];
	while(++i<line)
	{
		read(fd, c, col);
		k=-1;
		while(++k<col)
		{
			if(test_char(c[k], tab)==0)
				return 0;
			tab[i][k].car=c[k];
			tab[i][k].colonne=line-i-1;
			tab[i][k].ligne=nb_empty(tab, c, col, k);
		}
		if(read(fd, c, 2)>0 && c[0]!='\r')
			return 0;
	}
	close(fd);
	return 1;
}

int test_line(t_elt **tab, int i, int j, int max)
{
	int k;

	k=-1;
	while(++k<=max)
		if(tab[i+max][j+k].car!=tab[0][0].car)
			return 0;
	return 1;
}

int test_col(t_elt **tab, int i, int j, int max)
{
	int k;

	k=-1;
	while(++k<=max)
		if(tab[i+k][j+max].car!=tab[0][0].car)
			return 0;
	return 1;
}

/*
int maxi(char **tab, char *init, int i, int j, int line, int col, int max)
{
	if(tab[i][j]!=init[0])
		return 0;
	if(i+max>=line || j+max>=col)
		return max;
	if(test_line(tab, init, i, j, max)==0 || test_col(tab, init, i, j, max)==0)
		return max;
	int temp;
	int temp2;

	if(i+1<line && j+1<col)
	{
		temp=maxi(tab, init, i+1, j, line, col, 0);
		temp2=maxi(tab, init, i+1, j, line, col, 0);
		if(temp!=temp2)
			return maxi(tab, init, i, j, line, col, min(temp,temp2)+1);
		if(tab[i+m][j+m]==init[0])
			return maxi(tab, init, i, j, line, col, temp+1);
		return maxi(tab, init, i, j, line, col, temp);
	}
	return maxi(tab, init, i, j, line, col,)

}
*/
int maxi(t_elt **tab, int i, int j)
{
	int max;

	max=0;
	while(max<=tab[i][j].ligne && max<=tab[i][j].colonne)
	{
		if(test_line(tab, i, j, max)==0 || test_col(tab, i, j, max)==0)
			return max;
		max++;
	}
	return max;
}

void repl_col(t_elt **tab,  int i, int j, int max)
{
	int k;

	k=-1;
	while(++k<=max)
		tab[i+k][j+max].car=tab[0][2].car;
}

void repl_line(t_elt **tab,  int i, int j, int max)
{
	int k;

	k=-1;
	while(++k<=max)
		tab[i+max][j+k].car=tab[0][2].car;
}

void replace(t_elt **tab, int i, int j, int max)
{
	int temp;

	temp=-1;
	while(++temp<max)
	{
		repl_col(tab,i, j, temp);
		repl_line(tab,i, j, temp);
	}
}