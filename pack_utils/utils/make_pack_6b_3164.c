/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3164.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3164(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,pb,pb,rb,ss,pb,sb,pb,pb,rrb");
	if (perm_label[4] == '5')
		return ("pb,pb,pb,rr,ss,pb,sb,rra,pb,pb,rrb");
	return (NULL);
}
