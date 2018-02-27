#include "ft_btree_rb.h"

void node(t_rb_node *root, int (*cmpf)(char *, char *), char *data)
{
		if(root==NULL)
			return ;
		if(cmpf(root->data, data)==0)
		{
//			printf("trouvé\n");
			suppr(root, cmpf, data);
		}
		node(root->left,  cmpf, data);
		node(root->right, cmpf, data);
}

void suppr(t_rb_node *root, int (*cmpf)(char *, char *), char *data)
{
	t_rb_node *temp;
	temp=root;
	if((root->left==NULL || root->right==NULL) && cmpf(root->data, data)==0)
	{
		if(root->left!=NULL)
			root=root->left;
		else if(root->right!=NULL)
			root=root->right;
		else
		{
			if ((root->parent)->left!=NULL)
				if((root->parent)->left==root)
					(root->parent)->left=NULL;
			if ((root->parent)->right!=NULL)
				if((root->parent)->right==root)
				(root->parent)->right=NULL;
		}
		root->parent=temp->parent;
		if ((temp->parent)->left!=NULL)
			if((temp->parent)->left==temp)
				(temp->parent)->left=root;
		if ((root->parent)->right!=NULL)
			if((root->parent)->right==root)
				(temp->parent)->right=root;
		free(temp);
	}
	else if((root->right)->right==NULL && (root->right)->left==NULL)
	{
		root->data=(root->right)->data;
		free(root->right);
		root->right=NULL;
	}
	else
	{	
		root->data=(root->right)->data;
		suppr(root->right, cmpf, data);
	}
}


/*void rb_remove(struct s_rb_node **root, void *data, int (*cmpf)(void *, void *), void (*freef)(void *))
{

}
*/