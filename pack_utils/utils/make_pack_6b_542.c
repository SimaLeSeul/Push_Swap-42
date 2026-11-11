/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_542.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_542(char *perm_label)
{
	if (perm_label[3] == '1')
		return (make_pack_6b_5421(perm_label));
	if (perm_label[3] == '3')
		return (make_pack_6b_5423(perm_label));
	if (perm_label[3] == '6')
		return (make_pack_6b_5426(perm_label));
	return (NULL);
}
