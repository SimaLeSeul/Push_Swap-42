/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6345.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6345(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("sa,pb,pb,rr,rr,pb,pb,rra,rrr,pb,pb,rrb");
	if (perm_label[4] == '2')
		return ("pb,rb,pb,pb,pb,rb,rb,rb,pb,rb,pb,rb");
	return (NULL);
}
