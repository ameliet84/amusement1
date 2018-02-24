#include "ft_btree.h"

void btree_insert_data(t_btree **root, char *item, int (*cmpf)(char *, char *))
{
	t_btree *new;
	new=btree_create_node(item);

	if(*root==NULL)
		*root=new;
	else if(cmpf((*root)->item, item)<0)
		(*root)->left=new;
	else
		(*root)->right = new;
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
		root=new;
		while(++i<argc)
		{
			btree_insert_data(&root, argv[i], &ft_strcmp);
			if(ft_strcmp((char *)root->item, argv[i])<0)
				root=root->left;
			else
				root=root->right;
		}
		printf("level: %d\n", btree_level_count(new));
	}
	return 0;
}