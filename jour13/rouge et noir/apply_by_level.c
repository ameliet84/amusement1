#include "ft_btree.h"

int power(int pwr)
{
	int nb;

	nb=1;
	while(pwr>0)
	{
		nb*=2;
		pwr--;
	}
	return nb;
}

void init_tab(t_btree **tab, int size)
{
	int i;

	i=0;
	while(i<size)
		tab[i++]=NULL;
}

void fill_tab(t_btree **tab, t_btree *root, int level, int current_level)
{
	if(level==current_level)
	{
		int i;

		i=0;
		while(tab[i]!=NULL)
			i++;
		tab[i]=root;
	}
}

void elem(t_btree **tab, t_btree *root, int level, int current_level)
{
	if(root==NULL)
		return;
	elem(tab, root->left, level+1, current_level);
	elem(tab, root->right, level+1, current_level);
	fill_tab(tab, root, level, current_level);
}

void elem_applyf(t_btree **tab, int current_level, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int i;

	i=0;
	while(tab[i]!=NULL)
	{
		if(i==0)
			applyf(tab[i]->item, current_level, 1);
		else
			applyf(tab[i]->item, current_level, 0);
		i++;
	}
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_btree **tab;
	int current_level;

	current_level=0;
	while(current_level<btree_level_count(root))
	{
		tab=malloc(sizeof(t_btree *)*power(current_level)+1);
		init_tab(tab, power(current_level)+1);
		elem(tab, root, 0, current_level);
		elem_applyf(tab, current_level, applyf);
		free(tab);
		current_level++;
	}
}