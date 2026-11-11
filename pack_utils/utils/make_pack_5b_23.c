/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_23.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packing_utils.h"

char	*make_pack_5b_23(char *perm_label)
{
	if (perm_label[2] == '1')
		return (make_pack_5b_231(perm_label));
	if (perm_label[2] == '4')
		return (make_pack_5b_234(perm_label));
	if (perm_label[2] == '5')
		return (make_pack_5b_235(perm_label));
	return (NULL);
}
