/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_5a(char *perm_label)
{
	if (perm_label[0] == '1')
		return (make_pack_5a_1(perm_label));
	if (perm_label[0] == '2')
		return (make_pack_5a_2(perm_label));
	if (perm_label[0] == '3')
		return (make_pack_5a_3(perm_label));
	if (perm_label[0] == '4')
		return (make_pack_5a_4(perm_label));
	if (perm_label[0] == '5')
		return (make_pack_5a_5(perm_label));
	return (NULL);
}
