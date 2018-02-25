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