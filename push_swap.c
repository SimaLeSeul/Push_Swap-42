#include "push_swap.h"

t_ps_state	*str_to_list(char **str, size_t len)
{
	t_ps_state	*ap;

	ap = malloc(sizeof(t_ps_state));
	if (ap == NULL)
		return (NULL);
	ap->a = str;
	ap->b = calloc(len + 1, sizeof(char *));
	if (ap->b == NULL)
	{
		free (ap);
		return (NULL);
	}
	ap->pa = len;
	ap->pb = 0;
	ap->tlen = len;
	return (ap);
}
