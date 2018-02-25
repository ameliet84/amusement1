#include "ft_btree.h"

void btree_apply_suffix(t_bree *root, void (*applyf)(void *))
{
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	if(root->item!=NULL)
		(*applyf)(root->item);
}