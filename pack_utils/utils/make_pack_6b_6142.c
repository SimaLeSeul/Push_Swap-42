/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6142.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6142(char *perm_label)
{
	if (perm_label[4] == '3')
		return ("sa,pb,pb,rr,pb,pb,rra,pb,pb,rrb");
	if (perm_label[4] == '5')
		return ("pb,rb,pb,pb,pb,ss,pb,sb,pb,rrb");
	return (NULL);
}
