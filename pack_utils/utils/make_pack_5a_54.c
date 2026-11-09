/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_54.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_5a_54(char *perm_label)
{
	if (perm_label[2] == '1')
		return (make_pack_5a_541(perm_label));
	if (perm_label[2] == '2')
		return (make_pack_5a_542(perm_label));
	if (perm_label[2] == '3')
		return (make_pack_5a_543(perm_label));
	return (NULL);
}
