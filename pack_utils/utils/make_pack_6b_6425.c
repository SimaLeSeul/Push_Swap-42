/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6425.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6425(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,rr,pb,sa,pb,ss,pb,rra,pb,pb,rrb");
	if (perm_label[4] == '3')
		return ("sa,pb,rr,pb,ra,sa,pb,sb,pb,rrr,pb,rra,pb");
	return (NULL);
}
