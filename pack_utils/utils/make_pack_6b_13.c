/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_13.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_13(char *perm_label)
{
	if (perm_label[2] == '2')
		return (make_pack_6b_132(perm_label));
	if (perm_label[2] == '4')
		return (make_pack_6b_134(perm_label));
	if (perm_label[2] == '5')
		return (make_pack_6b_135(perm_label));
	if (perm_label[2] == '6')
		return (make_pack_6b_136(perm_label));
	return (NULL);
}
