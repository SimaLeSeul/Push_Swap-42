/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6351.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6351(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,pb,ss,rb,pb,ss,pb,ss,pb,pb,rrb");
	if (perm_label[4] == '4')
		return ("ra,pb,pb,rb,pb,ss,pb,sb,pb,rrr,pb");
	return (NULL);
}
