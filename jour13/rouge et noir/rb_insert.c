#include "ft_btree_rb.h"


void repare(t_rb_node *root)
{
	if(!(root->parent))
		root->color=RB_BLACK;
	else if((root->parent)->color==RB_BLACK)
		return;
	else if(uncle(root)->color==RB_RED && uncle(root)->data!=NULL)
	{
		t_uncle(root);
		repare((root->parent)->parent);
	}
	else
	{
		rotate(root);
		repare(racine(root));
	}
}

void rb_insert(struct s_rb_node **root, void *data, int (*cmpf)(char *, char *))
{
	t_rb_node *new;
	if(!root)
		new=btree_create_node(data, NULL);
	if(cmpf((*root)->data, data)>0)
	{
		if((*root)->left!=NULL)
		{
			rb_insert(&(*root)->left, data, cmpf);
			return;
		}
		else
		{
			(*root)->left=btree_create_node(data, *root);
			new=(*root)->left;
		}
	}
	else 
	{
		if((*root)->right!=NULL)
		{
			rb_insert(&(*root)->right, data, cmpf);
			return;
		}
		else
		{
			(*root)->right=btree_create_node(data, *root);
			new=(*root)->right;
		}
	}
	repare(new);		
}

void print_node(t_rb_node *root)
{
	printf("item = %s\n", (char *)root->data);
	if(root->parent!=NULL)
		printf("parent = %s\n", (char *)(root->parent)->data);
	else
		printf("parent =NULL\n");
	if(root->left!=NULL)
		printf("left = %s\n", (char *)(root->left)->data);
	else
		printf("left=NULL\n");
	if(root->right!=NULL)
		printf("right = %s\n", (char *)(root->right)->data);
	else
		printf("right =NULL\n");
	printf("color = %d\n\n\n", (int)root->color);

}

void print_tree(t_rb_node *root)
{
	if(!root)
		return;
	print_node(root);
	print_tree(root->left);
	print_tree(root->right);
}

int main(int argc, char **argv)
{
	if(argc>1)
	{
		t_rb_node *new;
		t_rb_node *root;
		int i;

		i=1;
		new=btree_create_node(argv[1], NULL);
		new->color=RB_BLACK;
		while(++i<argc-1)
		{
			root=racine(new);
			rb_insert(&root, argv[i], &ft_strcmp);
		}
	root=racine(new);
	print_tree(root);
	root=racine(new);
	new=btree_create_node(NULL, NULL);
	node(root,&ft_strcmp, argv[argc-1]);
	printf("\n\n\net maintenant : \n\n");
	print_tree(root);
	}
	return 0;
}