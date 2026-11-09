/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5231.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5231(char *perm_label)
{
	if (perm_label[4] == '4')
		return ("pb,pb,ss,rb,pb,sb,pb,pb,rrb,pb");
	if (perm_label[4] == '6')
		return ("sa,pb,pb,rr,pb,ss,rra,pb,pb,rrb,pb");
	return (NULL);
}
