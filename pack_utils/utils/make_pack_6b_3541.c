/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3541.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3541(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,pb,rb,rr,pb,pb,rrr,pb,rrb,pb");
	if (perm_label[4] == '6')
		return ("pb,sa,pb,rr,pb,ss,pb,sb,rrr,pb,pb");
	return (NULL);
}
