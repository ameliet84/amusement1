#include "ft_btree_rb.h"

void node(t_rb_node *new, t_rb_node *root, int (*cmpf)(char *, char *), char *data)
{
	printf("entrée et data =%s, et root=%s\n", data, (char *)root->data);
		if(root==NULL)
			return ;
		if(cmpf(root->data, data)==0)
		{
			printf("trouvé\n");
			new=root;
		}
		node(new, root->left, cmpf, data);
		node(new, root->right, cmpf, data);
}

void suppr(t_rb_node *node, t_rb_node *root)
{
	t_rb_node *temp;
	temp=root;
	if(node->left==NULL || node->right==NULL)
	{
		if(node->left!=NULL)
			root=root->left;
		else
			root=root->right;
			root->parent=temp->parent;
	}
	if((root->left)->right==NULL && (root->left)->left==NULL)
	{
		free(root->left);
		return;
	}
	else
	{	
		root=root->right;
		root->parent=temp->parent;
		suppr(node, root);
	}
}


/*void rb_remove(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *), void (*freef)(void *))
{

}
*/