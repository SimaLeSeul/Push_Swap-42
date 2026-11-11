/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_4a_4.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_4a_4(char *perm_label)
{
	if (perm_label[1] == '1')
		return (make_pack_4a_41(perm_label));
	if (perm_label[1] == '2')
		return (make_pack_4a_42(perm_label));
	if (perm_label[1] == '3')
		return (make_pack_4a_43(perm_label));
	return (NULL);
}
