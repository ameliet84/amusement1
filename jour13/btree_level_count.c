#include "ft_btree.h"

int max(int a, int b)
{
	if(a<b)
		return b;
	return a;
}


int btree_level_count(t_btree *root)
{
if(root==NULL)
	return 0;
else
	return (1+max(btree_level_count(root->left),btree_level_count(root->right)));
}