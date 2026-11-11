/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_513.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_513(char *perm_label)
{
	if (perm_label[3] == '2')
		return (make_pack_6b_5132(perm_label));
	if (perm_label[3] == '4')
		return (make_pack_6b_5134(perm_label));
	if (perm_label[3] == '6')
		return (make_pack_6b_5136(perm_label));
	return (NULL);
}
