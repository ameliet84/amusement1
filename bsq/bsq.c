#include "bsq.h"

void find(t_elt ** tab, int line, int col)
{
	t_coord point;
	t_coord maximum;
	int max;
	int temp;
	int nb;

	nb=0;
	point.line=0;
	max=0;
	while(++point.line<line)
	{
		point.col=-1;
		while(++point.col<col)
		{
			if(tab[point.line][point.col].car==tab[0][0].car && tab[point.line][point.col].ligne>max && tab[point.line][point.col].colonne>max)
			{
				nb++;
				temp=maxi(tab, point.line, point.col);
				if(max<temp)
				{
					maximum.line=point.line;
					maximum.col=point.col;
					max=temp;
				}
			}
		}
	}
	printf("maxxxxx=%d et nbr testés=%d\n", maxi(tab, maximum.line, maximum.col), nb);
	replace(tab, maximum.line, maximum.col, max);
}


void bsq(char *file)
{
	int line;
	int col;
	t_elt **tab;
	int i;
	time_t debut;
	time_t fin;

	i=0;
	debut=time(NULL);
	init_numbers(file, &line, &col);
	printf("lignes= %d et col = %d\n", line, col);
	tab=malloc(sizeof(t_elt *)*line+1);
	tab[0]=malloc(sizeof(t_elt)*3);
	i=1;
	while(i<line+1)
		tab[i++]=malloc(sizeof(t_elt)*col);
	if(init_tab(file, line+1, col, tab)==0)
		write(2, "map error\n", 11);
	else
	{
		find(tab, line+1, col);
		fin=time(NULL);
		print_tab(tab, line+1, col);
		printf("durée=%d secondes\n", (int)(fin-debut));
	}
}


int main(int argc, char **argv)
{
	int i;
	int fd;
	int c;
	if(argc>1)
	{
		i=0;
		while(++i<argc)
			bsq(argv[i]);
	}
	else
	{
		fd=open("text.txt", O_CREAT|O_WRONLY);
		while(read(0, &c, 1)>0)
			write(fd, &c, 1);
		close(fd);
		bsq("text.txt");
	}
	return 0;
}