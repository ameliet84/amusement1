#ifndef _FT_BTREE_RB_H_
#define _FT_BTREE_RB_H_

#include <stdio.h>
#include <stdlib.h>

enum e_rb_color
{
	RB_BLACK,
	RB_RED
};

typedef struct s_rb_node
{
	struct s_rb_node *parent;
	struct s_rb_node *right;
	struct s_rb_node *left;
	void *data;
	enum e_rb_color color;
} t_rb_node;

t_rb_node *btree_create_node(void *item, t_rb_node *parent);
t_rb_node *uncle(t_rb_node *root);
int ft_strcmp(char *s1, char *s2);
void t_uncle(t_rb_node *root);
void rot_left(t_rb_node *root);
void rot_right(t_rb_node *root);
void rotate(t_rb_node *root);
t_rb_node *racine(t_rb_node *root);
void print_tree(t_rb_node *root);
int max(char *a, char *b);
void node(t_rb_node *root, int (*cmpf)(char *, char *), char *data);
void suppr(t_rb_node *root, int (*cmpf)(char *, char *), char *data);
void print_node(t_rb_node *root);

#endif