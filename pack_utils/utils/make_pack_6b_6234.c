/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6234.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6234(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,rb,pb,pb,rr,pb,sb,rrr,pb,pb,rrb");
	if (perm_label[4] == '5')
		return ("pb,rb,pb,pb,pb,pb,rb,rb,rb,rb,pb,rb");
	return (NULL);
}
