/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_4265.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_4265(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,pb,ss,rr,sa,pb,ss,pb,rrr,pb,pb");
	if (perm_label[4] == '3')
		return ("pb,pb,pb,rr,ss,rb,pb,sb,pb,rrr,pb,rrb");
	return (NULL);
}
