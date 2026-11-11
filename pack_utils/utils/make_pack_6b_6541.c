/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6541.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6541(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,rr,pb,rb,pb,pb,pb,rrr,pb,rrb");
	if (perm_label[4] == '3')
		return ("pb,rr,pb,pb,ss,rb,pb,pb,rrr,pb,rrb");
	return (NULL);
}
