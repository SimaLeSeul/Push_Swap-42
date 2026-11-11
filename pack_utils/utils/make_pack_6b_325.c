/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_325.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_325(char *perm_label)
{
	if (perm_label[3] == '1')
		return (make_pack_6b_3251(perm_label));
	if (perm_label[3] == '4')
		return (make_pack_6b_3254(perm_label));
	if (perm_label[3] == '6')
		return (make_pack_6b_3256(perm_label));
	return (NULL);
}
