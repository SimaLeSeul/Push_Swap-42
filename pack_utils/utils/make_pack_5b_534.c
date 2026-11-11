/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_534.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5b_534(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("pb,rb,pb,rr,pb,pb,rrr,pb,rrb");
	if (perm_label[3] == '2')
		return ("pb,rb,pb,pb,rb,rb,pb,rb,pb,rb");
	return (NULL);
}
