/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5463.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5463(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("ra,pb,rr,pb,rb,pb,pb,rrr,rrr,pb,pb");
	if (perm_label[4] == '2')
		return ("ra,pb,rr,pb,sa,rb,pb,pb,rrr,rrr,pb,pb");
	return (NULL);
}
