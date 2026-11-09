/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_15.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_5a_15(char *perm_label)
{
	if (perm_label[2] == '2')
		return (make_pack_5a_152(perm_label));
	if (perm_label[2] == '3')
		return (make_pack_5a_153(perm_label));
	if (perm_label[2] == '4')
		return (make_pack_5a_154(perm_label));
	return (NULL);
}
