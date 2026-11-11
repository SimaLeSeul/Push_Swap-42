/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_635.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_635(char *perm_label)
{
	if (perm_label[3] == '1')
		return (make_pack_6b_6351(perm_label));
	if (perm_label[3] == '2')
		return (make_pack_6b_6352(perm_label));
	if (perm_label[3] == '4')
		return (make_pack_6b_6354(perm_label));
	return (NULL);
}
