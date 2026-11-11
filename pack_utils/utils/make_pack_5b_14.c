/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_14.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_5b_14(char *perm_label)
{
	if (perm_label[2] == '2')
		return (make_pack_5b_142(perm_label));
	if (perm_label[2] == '3')
		return (make_pack_5b_143(perm_label));
	if (perm_label[2] == '5')
		return (make_pack_5b_145(perm_label));
	return (NULL);
}
