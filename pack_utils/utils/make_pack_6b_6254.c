/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6254.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6254(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("ra,pb,pb,sa,rb,pb,ss,pb,pb,rrr,pb");
	if (perm_label[4] == '3')
		return ("pb,rb,pb,pb,rb,pb,rb,pb,rb,rb,pb,rb");
	return (NULL);
}
