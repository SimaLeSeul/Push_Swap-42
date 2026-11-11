/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_621.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_621(char *perm_label)
{
	if (perm_label[3] == '3')
		return (make_pack_6b_6213(perm_label));
	if (perm_label[3] == '4')
		return (make_pack_6b_6214(perm_label));
	if (perm_label[3] == '5')
		return (make_pack_6b_6215(perm_label));
	return (NULL);
}
