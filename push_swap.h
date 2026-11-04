#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_ps_state
{
	int		*a;
	int		*b;
	size_t	pa;
	size_t	pb;
	size_t	tlen;
}			t_ps_state;

t_ps_state	*str_to_list(int *arr, size_t len);
void		freexit(t_ps_state *state);

int			is_whitespace(char c);
int			ft_atoi(const char *s);
int			contains_value(int *tab, size_t count, int value);
size_t		argtoint(const char *s, int *res, t_ps_state *state, size_t count);

char		**flags_parser(const char *s);
void		free_flags(char **flags);
void		flags_handler(const char *s);

void		op_sa(t_ps_state state);
void		op_sb(t_ps_state state);
void		op_ss(t_ps_state state);
void		op_pa(t_ps_state state);
void		op_pb(t_ps_state state);
void		op_ra(t_ps_state state);
void		op_rb(t_ps_state state);
void		op_rr(t_ps_state state);
void		op_rra(t_ps_state state);
void		op_rrb(t_ps_state state);
void		op_rrr(t_ps_state state);
#endif
