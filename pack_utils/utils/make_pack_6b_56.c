/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_56.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_56(char *perm_label)
{
	if (perm_label[2] == '1')
		return (make_pack_6b_561(perm_label));
	if (perm_label[2] == '2')
		return (make_pack_6b_562(perm_label));
	if (perm_label[2] == '3')
		return (make_pack_6b_563(perm_label));
	if (perm_label[2] == '4')
		return (make_pack_6b_564(perm_label));
	return (NULL);
}
