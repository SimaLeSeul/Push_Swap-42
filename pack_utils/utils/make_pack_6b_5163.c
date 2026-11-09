/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5163.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5163(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("sa,pb,pb,rr,sa,pb,pb,pb,rrr,pb");
	if (perm_label[4] == '4')
		return ("sa,pb,pb,rr,pb,sa,pb,sb,pb,rrr,pb");
	return (NULL);
}
