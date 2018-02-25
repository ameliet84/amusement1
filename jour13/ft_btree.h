#ifndef _FT_BTREE_H_
#define _FT_BTREE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct s_btree
{
		struct s_btree *left;
		struct s_btree *right;
		void *item;
}			t_btree;

t_btree *btree_create_node(void *item);
int btree_level_count(t_btree *root);
int ft_strcmp(char *s1, char *s2);
void btree_insert_data(t_btree **root, char *item, int (*cmpf)(char *, char *));
void btree_apply_by_level(t_btree *root);

#endif