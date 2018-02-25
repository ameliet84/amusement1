#include "ft_btree.h"

void btree_insert_data(t_btree **root, char *item, int (*cmpf)(char *, char *))
{
	t_btree *new;

	new=btree_create_node(item);
	if(*root==NULL)
		*root=new;
	else if(cmpf((*root)->item, item)>0)
	{
		if((*root)->left!=NULL)
			btree_insert_data(&(*root)->left, item, cmpf);
		else
		{
		printf("left: parent = %s et item = %s\n", (char *)(*root)->item, item);
			(*root)->left=new;
		}
	}
	else 
	{
		if((*root)->right!=NULL)
			btree_insert_data(&(*root)->right, item, cmpf);
		else
		{
		printf("right: parent = %s et item = %s\n", (char *)(*root)->item, item);
			(*root)->right = new;
		}
	}		
}

void btree_prefix(t_btree *root)
{
	if(root==NULL)
		return;
	printf("%s\n", (char *)root->item);
	btree_prefix(root->left);
	btree_prefix(root->right);
}

int main(int argc, char **argv)
{
	if(argc>1)
	{
		int i;
		t_btree *new;
		t_btree *root;

		i=1;
		new=btree_create_node(argv[1]);
		while(++i<argc)
		{
			root=new;
			btree_insert_data(&root, argv[i], &ft_strcmp);
		}
		btree_apply_by_level(new);
		printf("count = %d\n", btree_level_count(new));
	}
	return 0;
}