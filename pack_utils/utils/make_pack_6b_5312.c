/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5312.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5312(char *perm_label)
{
	if (perm_label[4] == '4')
		return ("pb,rr,pb,pb,rra,pb,pb,rrb,pb");
	if (perm_label[4] == '6')
		return ("pb,sa,rb,pb,pb,pb,ss,pb,rrb,pb");
	return (NULL);
}
