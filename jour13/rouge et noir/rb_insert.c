#include "ft_btree_rb.h"

t_rb_node *btree_create_node(void *item, t_rb_node *parent)
{
	t_rb_node *new;

	new=malloc(sizeof(t_rb_node));
	new->data =item;
	new->left=NULL;
	new->right=NULL;
	new->parent=parent;
	new->color=RB_RED;
	return new;
}

t_rb_node *uncle(t_rb_node *root)
{
	if((root->parent)->parent!=NULL)
	{
		if(((root->parent)->parent)->left==root->parent)
			return ((root->parent)->parent)->right;
		else
			return ((root->parent)->parent)->left;
	}
}

void repare(t_rb_node *root)
{
	if(root->parent==NULL)
		root->color=RB_BLACK;
	else if((root->parent)->color==RB_BLACK)
		return;
	else if(uncle(root)->color==RB_RED)
		

}

void rb_insert(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *))
{
	t_rb_node *new;
	if(root==NULL)
		new=btree_create_node(data, *root);
	if(cmpf((*root)->data, data)>0)
	{
		if((*root)->left!=NULL)
		{
			rb_insert((*root)->left, data, cmpf);
			return;
		}
		else
			(*root)->left=btree_create_node(data, *root);
	}
	else 
	{
		if((*root)->right!=NULL)
		{
			rb_insert((*root)->right, data, cmpf);
			return;
		}
		else
			(*root)->right=btree_create_node(data, *root);
	}
	while((*root)->parent!=NULL)
		(*root)=(*root)->parent;


		
}