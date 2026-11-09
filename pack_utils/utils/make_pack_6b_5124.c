/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5124.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5124(char *perm_label)
{
	if (perm_label[4] == '3')
		return ("pb,rb,pb,pb,sa,pb,pb,rrb,pb");
	if (perm_label[4] == '6')
		return ("pb,rb,pb,pb,pb,sa,pb,sb,rrb,pb");
	return (NULL);
}
