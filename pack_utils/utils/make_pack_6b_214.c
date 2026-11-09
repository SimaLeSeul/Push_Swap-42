/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_214.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_214(char *perm_label)
{
	if (perm_label[3] == '3')
		return (make_pack_6b_2143(perm_label));
	if (perm_label[3] == '5')
		return (make_pack_6b_2145(perm_label));
	if (perm_label[3] == '6')
		return (make_pack_6b_2146(perm_label));
	return (NULL);
}
