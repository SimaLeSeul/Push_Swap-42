/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5643.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5643(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,ra,rr,pb,rb,pb,pb,rrr,pb,rrr,pb");
	if (perm_label[4] == '2')
		return ("pb,pb,rb,rb,pb,rb,pb,rb,pb,rb,pb,rb");
	return (NULL);
}
