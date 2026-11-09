/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_4652.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_4652(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,pb,rb,rr,sa,pb,pb,pb,rrr,pb,rrb");
	if (perm_label[4] == '3')
		return ("pb,pb,rb,pb,rb,rb,pb,pb,rb,rb,pb,rb");
	return (NULL);
}
