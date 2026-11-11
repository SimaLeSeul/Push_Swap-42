/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3612.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3612(char *perm_label)
{
	if (perm_label[4] == '4')
		return ("pb,rr,pb,pb,pb,rrr,ss,pb,pb");
	if (perm_label[4] == '5')
		return ("pb,pb,rb,pb,sb,pb,ss,pb,pb,rrb");
	return (NULL);
}
