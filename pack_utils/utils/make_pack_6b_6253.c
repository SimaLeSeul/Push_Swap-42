/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6253.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6253(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("ra,pb,pb,sa,rb,pb,sb,pb,pb,rrr,pb");
	if (perm_label[4] == '4')
		return ("pb,rb,pb,pb,rb,pb,pb,rb,rb,rb,pb,rb");
	return (NULL);
}
