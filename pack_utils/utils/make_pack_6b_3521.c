/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3521.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3521(char *perm_label)
{
	if (perm_label[4] == '4')
		return ("pb,rr,sa,pb,pb,pb,rrr,sb,pb,pb");
	if (perm_label[4] == '6')
		return ("pb,rr,pb,pb,ss,pb,rrr,sb,pb,pb");
	return (NULL);
}
