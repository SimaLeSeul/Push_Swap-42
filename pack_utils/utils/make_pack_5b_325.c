/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_325.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5b_325(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("pb,pb,ss,rb,pb,ss,rrb,pb,pb");
	if (perm_label[3] == '4')
		return ("pb,pb,ss,rr,sa,pb,sb,rrr,pb,pb");
	return (NULL);
}
