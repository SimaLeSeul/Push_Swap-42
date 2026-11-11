/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_64.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_64(char *perm_label)
{
	if (perm_label[2] == '1')
		return (make_pack_6b_641(perm_label));
	if (perm_label[2] == '2')
		return (make_pack_6b_642(perm_label));
	if (perm_label[2] == '3')
		return (make_pack_6b_643(perm_label));
	if (perm_label[2] == '5')
		return (make_pack_6b_645(perm_label));
	return (NULL);
}
