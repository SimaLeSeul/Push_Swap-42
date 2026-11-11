/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_543.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_543(char *perm_label)
{
	if (perm_label[3] == '1')
		return (make_pack_6b_5431(perm_label));
	if (perm_label[3] == '2')
		return (make_pack_6b_5432(perm_label));
	if (perm_label[3] == '6')
		return (make_pack_6b_5436(perm_label));
	return (NULL);
}
