#ifndef _FT_LIST_H_
#define _FT_LIST_H_

#include<stdlib.h>
typedef struct s_list
{
	void *param;
	struct s_list *next;
} t_list;

#endif