/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_4561.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_4561(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,pb,rb,rr,pb,pb,pb,rrb,rrr,pb");
	if (perm_label[4] == '3')
		return ("pb,pb,rb,rr,pb,sa,pb,pb,rrb,rrr,pb");
	return (NULL);
}
