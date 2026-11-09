/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3264.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3264(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,pb,ss,rr,sa,pb,ss,rrr,pb,pb,pb");
	if (perm_label[4] == '5')
		return ("pb,pb,pb,rr,ss,rb,pb,sb,rrr,pb,pb,rrb");
	return (NULL);
}
