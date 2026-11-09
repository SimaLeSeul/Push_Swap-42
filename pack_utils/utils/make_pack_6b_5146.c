/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5146.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5146(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,rb,pb,pb,rr,pb,pb,rrb,rrr,pb");
	if (perm_label[4] == '3')
		return ("pb,rb,pb,pb,rr,sa,pb,pb,rrb,rrr,pb");
	return (NULL);
}
