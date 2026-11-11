/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_2b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 00:40:51 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/11 00:41:13 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_2b(char *perm_label)
{
	if (perm_label[0] == '1')
		return ("pb,pb");
	if (perm_label[0] == '2')
		return ("sa,pb,pb");
	return (NULL);
}
