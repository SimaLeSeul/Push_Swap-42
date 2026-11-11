/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6341.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6341(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,rb,pb,rr,pb,pb,rrr,pb,pb,rrb");
	if (perm_label[4] == '5')
		return ("pb,rb,pb,rr,pb,sa,pb,rrr,pb,pb,rrb");
	return (NULL);
}
