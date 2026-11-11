/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_523.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5b_523(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("pb,pb,ss,rb,pb,sb,pb,pb,rrb");
	if (perm_label[3] == '4')
		return ("pb,rb,pb,pb,pb,rb,rb,rb,pb,rb");
	return (NULL);
}
