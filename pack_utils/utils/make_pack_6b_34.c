/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_34.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_34(char *perm_label)
{
	if (perm_label[2] == '1')
		return (make_pack_6b_341(perm_label));
	if (perm_label[2] == '2')
		return (make_pack_6b_342(perm_label));
	if (perm_label[2] == '5')
		return (make_pack_6b_345(perm_label));
	if (perm_label[2] == '6')
		return (make_pack_6b_346(perm_label));
	return (NULL);
}
