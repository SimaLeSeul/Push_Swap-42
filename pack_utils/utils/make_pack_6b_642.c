/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_642.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_642(char *perm_label)
{
	if (perm_label[3] == '1')
		return (make_pack_6b_6421(perm_label));
	if (perm_label[3] == '3')
		return (make_pack_6b_6423(perm_label));
	if (perm_label[3] == '5')
		return (make_pack_6b_6425(perm_label));
	return (NULL);
}
