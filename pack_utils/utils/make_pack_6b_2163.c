/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_2163.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_2163(char *perm_label)
{
	if (perm_label[4] == '4')
		return ("sa,pb,pb,pb,rb,pb,pb,pb,rrb");
	if (perm_label[4] == '5')
		return ("sa,pb,pb,pb,pb,ss,pb,sb,pb,sb");
	return (NULL);
}
