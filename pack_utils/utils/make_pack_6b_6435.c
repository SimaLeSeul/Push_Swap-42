/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6435.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6435(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,rr,pb,rr,pb,pb,rra,rrr,pb,pb,rrb");
	if (perm_label[4] == '2')
		return ("pb,rr,pb,rr,sa,pb,pb,rra,rrr,pb,pb,rrb");
	return (NULL);
}
