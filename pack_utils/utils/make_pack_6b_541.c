/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_541.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_541(char *perm_label)
{
	if (perm_label[3] == '2')
		return (make_pack_6b_5412(perm_label));
	if (perm_label[3] == '3')
		return (make_pack_6b_5413(perm_label));
	if (perm_label[3] == '6')
		return (make_pack_6b_5416(perm_label));
	return (NULL);
}
