/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3452.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3452(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,pb,rb,rr,sa,pb,pb,rrb,rrr,pb,pb");
	if (perm_label[4] == '6')
		return ("pb,pb,rb,rr,pb,sa,pb,sb,rrb,rrr,pb,pb");
	return (NULL);
}
