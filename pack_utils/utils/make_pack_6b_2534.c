/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_2534.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_2534(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,pb,rb,pb,rr,pb,sb,rrr,pb,rrb,pb");
	if (perm_label[4] == '6')
		return ("pb,pb,pb,ss,rr,rr,pb,sb,rrr,pb,rrr,pb");
	return (NULL);
}
