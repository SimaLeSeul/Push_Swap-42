/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_2346.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_2346(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,pb,rr,sa,pb,ss,rrr,pb,pb,pb");
	if (perm_label[4] == '5')
		return ("pb,pb,pb,sa,rr,rr,pb,sb,rrr,rrr,pb,pb");
	return (NULL);
}
