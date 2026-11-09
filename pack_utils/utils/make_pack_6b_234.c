/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_234.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_234(char *perm_label)
{
	if (perm_label[3] == '1')
		return (make_pack_6b_2341(perm_label));
	if (perm_label[3] == '5')
		return (make_pack_6b_2345(perm_label));
	if (perm_label[3] == '6')
		return (make_pack_6b_2346(perm_label));
	return (NULL);
}
