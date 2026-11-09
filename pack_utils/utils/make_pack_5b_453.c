/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_453.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5b_453(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("pb,ra,rr,pb,pb,rra,pb,rrr,pb");
	if (perm_label[3] == '2')
		return ("pb,pb,rb,rb,pb,rb,pb,rb,pb,rb");
	return (NULL);
}
