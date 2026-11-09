/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5423.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5423(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("sa,pb,rr,pb,sa,pb,sb,pb,rrr,pb,pb");
	if (perm_label[4] == '6')
		return ("sa,pb,rr,pb,pb,rr,pb,sb,rrr,rrr,pb,pb");
	return (NULL);
}
