#include "ft_btree_rb.h"

int max(char *a, char *b)
{
	if(atoi(a)<atoi(b))
		return -1;
	return 1;
}

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
		if(((root->parent)->parent)->left==root->parent &&  ((root->parent)->parent)->right!=NULL)
			return ((root->parent)->parent)->right;
		else if(((root->parent)->parent)->right==root->parent &&  ((root->parent)->parent)->left!=NULL)
			return ((root->parent)->parent)->left;
	}
	return btree_create_node(NULL, NULL);
}

void t_uncle(t_rb_node *root)
{
	(root->parent)->color=RB_BLACK;
	uncle(root)->color=RB_BLACK;
	((root->parent)->parent)->color=RB_RED;
}

void rot_left(t_rb_node *root)
{
	t_rb_node *temp;
	t_rb_node *temp1;
	
	temp=root->parent;
	temp1=root->left;
	root->parent=temp->parent;
	if(temp->parent!=NULL)
	{
		if((temp->parent)->left==temp)
			(temp->parent)->left=root;
		else
			(temp->parent)->right=root;
	}
	root->left=temp;
	if(root->left!=NULL)
		(root->left)->parent=root;
	(root->left)->right=temp1;
	if((root->left)->right!=NULL)
		((root->left)->right)->parent=root->left;	
}

void rot_right(t_rb_node *root)
{
	t_rb_node *temp;
	t_rb_node *temp1;
	
	temp=root->parent;
	temp1=root->right;
	root->parent=temp->parent;
	if(temp->parent!=NULL)
	{
		if ((temp->parent)->left==temp)
		(temp->parent)->left=root;
		else
			(temp->parent)->right=root;
	}
	root->right=temp;
	if(root->right!=NULL)
		(root->right)->parent=root;
	(root->right)->left=temp1;
	if(((root->right)->left)!=NULL)
		((root->right)->left)->parent=root->right;	
}

void rotate(t_rb_node *root)
{
	t_rb_node *p;
	t_rb_node *gp;

	p=root->parent;
	gp=p->parent;
	if((gp->left!=NULL))
		if((gp->left)->right!=NULL && root==(gp->left)->right)
		{
			rot_left(root);
			root=root->left;
		}
	if((gp->right)!=NULL)
		if((gp->right)->left!=NULL && root==(gp->right)->left)
		{
			printf("cas !!! et gp=%s%d et p=%s%d\n", (char *)gp->data, (int)gp->color, (char *)p->data, (int)p->color );
			rot_right(root);
			root=root->right;
		}
	p=root->parent;
	gp=p->parent;
	if(p->left==NULL) 
	{
		rot_left(p);
	}
	else
	{
		if( root==p->left)
			rot_right(p);
		else
			rot_left(p);
	}
	p->color=RB_BLACK;
	gp->color=RB_RED;
}

int ft_strcmp(char *s1, char *s2)
{
	int	i;

	i=0;
	while(s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0')
		i++;
		return s1[i]-s2[i];
}

t_rb_node *racine(t_rb_node *root)
{
	while(root->parent!=NULL)
		root=root->parent;
	return root;
}