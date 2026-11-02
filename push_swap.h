#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_ps_state
{
	char		**a;
	char		**b;
	size_t		pa;
	size_t		pb;
	size_t		tlen;
}			t_ps_state;

#endif