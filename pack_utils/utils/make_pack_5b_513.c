/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_513.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5b_513(char *perm_label)
{
	if (perm_label[3] == '2')
		return ("pb,pb,ss,rb,pb,pb,pb,rrb");
	if (perm_label[3] == '4')
		return ("pb,rb,pb,pb,sa,pb,sb,pb,rrb");
	return (NULL);
}
