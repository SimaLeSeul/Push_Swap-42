/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_2a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:38:52 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 00:40:07 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_2a(char *perm_label)
{
	if (perm_label[0] == '1')
		return ("ra,ra");
	if (perm_label[0] == '2')
		return ("sa,ra,ra");
	return (NULL);
}
