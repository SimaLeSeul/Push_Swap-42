/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_5.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_5a_5(char *perm_label)
{
	if (perm_label[1] == '1')
		return (make_pack_5a_51(perm_label));
	if (perm_label[1] == '2')
		return (make_pack_5a_52(perm_label));
	if (perm_label[1] == '3')
		return (make_pack_5a_53(perm_label));
	if (perm_label[1] == '4')
		return (make_pack_5a_54(perm_label));
	return (NULL);
}
