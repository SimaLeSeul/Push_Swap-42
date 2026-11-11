/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3416.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3416(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,pb,rb,pb,ss,pb,ss,rrb,pb,pb");
	if (perm_label[4] == '5')
		return ("pb,pb,pb,ss,rr,ss,pb,sb,rrr,pb,pb");
	return (NULL);
}
