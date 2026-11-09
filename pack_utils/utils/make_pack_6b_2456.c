/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_2456.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_2456(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,pb,rr,sa,pb,ss,pb,rrr,pb,pb");
	if (perm_label[4] == '3')
		return ("pb,pb,pb,pb,rb,rb,rb,pb,rb,rb,pb,rb");
	return (NULL);
}
