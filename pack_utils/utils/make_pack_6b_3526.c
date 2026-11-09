/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3526.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3526(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,rr,pb,sa,pb,ss,pb,rrr,sb,pb,pb");
	if (perm_label[4] == '4')
		return ("pb,sa,pb,sb,pb,rr,rr,pb,sb,rrr,pb,rrr,pb");
	return (NULL);
}
