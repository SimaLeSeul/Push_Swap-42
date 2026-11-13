/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibaboul <mibaboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 12:00:00 by mibaboul          #+#    #+#             */
/*   Updated: 2026/11/13 12:00:00 by mibaboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_ps_state	*checker_parse(int argc, char **argv)
{
	t_ps_state	*state;
	int			i;

	state = str_to_list();
	if (!state)
		freexit(state);
	i = 1;
	while (i < argc)
		argtoint(argv[i++], state);
	return (state);
}

static int	checker_read(t_ps_state *state, char *line)
{
	ssize_t	bytes;
	size_t	i;
	char	c;

	i = 0;
	bytes = read(0, &c, 1);
	while (bytes > 0)
	{
		if (c == '\n')
		{
			line[i] = '\0';
			return (1);
		}
		if (i == 3 || c == '\0')
			freexit(state);
		line[i++] = c;
		bytes = read(0, &c, 1);
	}
	if (bytes < 0 || i > 0)
		freexit(state);
	return (0);
}

static int	checker_sorted(const t_ps_state *state)
{
	t_node	*node;
	size_t	i;

	if (state->b.size != 0)
		return (0);
	node = state->a.top;
	i = 1;
	while (i < state->a.size)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps_state	*state;
	char		line[4];

	if (argc == 1)
		return (0);
	state = checker_parse(argc, argv);
	while (checker_read(state, line))
		checker_apply(state, line);
	if (checker_sorted(state))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_state(state);
	return (0);
}
