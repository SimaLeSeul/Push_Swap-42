/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_25.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_25(char *perm_label)
{
	if (perm_label[2] == '1')
		return (make_pack_6b_251(perm_label));
	if (perm_label[2] == '3')
		return (make_pack_6b_253(perm_label));
	if (perm_label[2] == '4')
		return (make_pack_6b_254(perm_label));
	if (perm_label[2] == '6')
		return (make_pack_6b_256(perm_label));
	return (NULL);
}
