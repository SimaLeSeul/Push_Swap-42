/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3265.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3265(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("sa,pb,pb,rr,sa,pb,ss,pb,rrr,ss,pb,pb");
	if (perm_label[4] == '4')
		return ("pb,pb,ss,pb,rr,rr,pb,sb,rrr,pb,rrr,pb");
	return (NULL);
}
