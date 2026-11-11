/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_521.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_6b_521(char *perm_label)
{
	if (perm_label[3] == '3')
		return (make_pack_6b_5213(perm_label));
	if (perm_label[3] == '4')
		return (make_pack_6b_5214(perm_label));
	if (perm_label[3] == '6')
		return (make_pack_6b_5216(perm_label));
	return (NULL);
}
