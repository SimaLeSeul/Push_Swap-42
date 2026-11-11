/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_4351.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_4351(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,rb,pb,rr,pb,pb,rrb,rrr,pb,pb");
	if (perm_label[4] == '6')
		return ("sa,pb,pb,rr,pb,ss,pb,sb,rrr,pb,pb");
	return (NULL);
}
