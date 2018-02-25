#include "ft_btree.h"

void btree_apply_prefix(t_bree *root, void (*applyf)(void *))
{
	if(root->item==NULL)
		return;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}