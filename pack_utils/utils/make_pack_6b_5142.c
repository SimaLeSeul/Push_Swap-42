/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5142.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5142(char *perm_label)
{
	if (perm_label[4] == '3')
		return ("ra,pb,pb,rb,pb,pb,rrr,pb,pb");
	if (perm_label[4] == '6')
		return ("pb,rb,pb,pb,pb,ss,pb,sb,rrb,pb");
	return (NULL);
}
