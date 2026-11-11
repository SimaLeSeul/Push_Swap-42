/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5314.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5314(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,rb,pb,pb,ss,pb,sb,pb,rrb,pb");
	if (perm_label[4] == '6')
		return ("ra,pb,pb,pb,rb,ss,pb,sb,rrr,pb,pb");
	return (NULL);
}
