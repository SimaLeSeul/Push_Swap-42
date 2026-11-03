#include "push_swap.h"

t_ps_state	*str_to_list(int *arr, size_t len)
{
	t_ps_state	*state;

	state = malloc(sizeof(t_ps_state));
	if (!state)
		return (NULL);
	state->a = arr;
	state->b = NULL;
	if (len > (size_t)-1 / sizeof(int))
		freexit(state);
	if (len != 0)
		state->b = malloc(len * sizeof(int));
	if (len != 0 && !state->b)
		freexit(state);
	state->pa = len;
	state->pb = 0;
	state->tlen = len;
	return (state);
}

void	freexit(t_ps_state *state)
{
	write(2, "Error\n", 6);
	if (state)
	{
		free(state->a);
		free(state->b);
		free(state);
	}
	exit(1);
}
