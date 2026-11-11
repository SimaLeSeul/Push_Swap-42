/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5136.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5136(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,pb,ss,rr,sa,pb,pb,pb,rrr,pb");
	if (perm_label[4] == '4')
		return ("pb,pb,ss,rr,pb,sa,pb,sb,pb,rrr,pb");
	return (NULL);
}
